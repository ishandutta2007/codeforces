#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

map<ll, int> sg[65];

int search(int stones, ll st)
{
    st &= ((1LL << (ll)(stones + 1)) - 1LL);
    if (sg[stones].count(st)) return sg[stones][st];
    if (!stones) {
        sg[0][0] = 0; return 0;
    }
    vector<int> new_sgs;
    for (int i = 1; i <= stones; i++) {
        if (!(st & (1LL << (ll)i))) {
            new_sgs.push_back(search(stones - i, st | (1LL << (ll)i)));
        }
    }
    int mex;
    sort(new_sgs.begin(), new_sgs.end());
    //printf("%d %lld: ", stones, st);
    /*for (int i = 0; i < new_sgs.size(); i++) {
        printf("%d ", new_sgs[i]);
    }
    printf("\n");*/
    if (new_sgs.size() == 0) {
        mex = 0;
    } else {
        if (new_sgs[0] > 0) {
            mex = 0;
        } else {
            mex = new_sgs[new_sgs.size() - 1] + 1;
            for (int i = 1; i < new_sgs.size(); i++) {
                if (new_sgs[i] > new_sgs[i-1] + 1) {
                    mex = new_sgs[i] - 1; break;
                }
            }
        }
    }
    sg[stones][st] = mex;
    //printf("%d %lld: %d\n", stones, st, mex);
    return mex;
}

int main()
{
    for (int i = 0; i <= 60; i++) {
        search(i, 0);
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    //printf("(%d)", sg[1][1]);
    //for (int i = 1; i <= 60; i++) printf("%d ", sg[i][0]);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        ans ^= sg[a][0];
    }
    if (ans == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}