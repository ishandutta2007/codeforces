#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int f[52][1500];
int prec[52][1500], prem[52][1500];

char tmp[1005];
int s[15][1005];
int l[15];
int occur[15][52][2];

int n;

bool cmp(pair<int, int> A, pair<int, int> B)
{
    for (int i = 0; i < n; i++) {
        int pos1 = occur[i][A.first][(A.second & (1 << i)) ? 1 : 0];
        int pos2 = occur[i][B.first][(B.second & (1 << i)) ? 1 : 0];
        if (pos1 != pos2) return pos1 < pos2;
    }
    return false;
}

void work()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 52; j++) {
            occur[i][j][0] = occur[i][j][1] = 100000;
        }
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        l[i] = strlen(tmp);
        for (int j = 0; tmp[j]; j++) {
            s[i][j] = (tmp[j] <= 'Z' ? tmp[j] - 'A' + 26 : tmp[j] - 'a');
            //printf("%d ", s[i][j]);
            if (occur[i][s[i][j]][0] == 100000) {
                occur[i][s[i][j]][0] = j;
            } else {
                occur[i][s[i][j]][1] = j;
            }
        }
    }
    vector<pair<int, int> > vec;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool good = true;
            for (int k = 0; k < n; k++) {
                if (occur[k][i][(j & (1 << k)) ? 1 : 0] == 100000) good = false;
            }
            if (good) vec.push_back(make_pair(i, j));
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    //debug("here");
    if (vec.empty()) {
        printf("0\n\n"); return;
    }
    int bestc = vec[0].first, bestm = vec[0].second;
    for (int i = 0; i < vec.size(); i++) {
        //debug("here %d %d\n", vec[i].first, vec[i].second);
        f[vec[i].first][vec[i].second] = 1;
        int pos[15];
        for (int j = 0; j < n; j++) {
            pos[j] = occur[j][vec[i].first][(vec[i].second & (1 << j)) ? 1 : 0];
        }
        for (int j = 0; j < 52; j++) {
            int msk = 0;
            bool good = true;
            for (int k = 0; k < n; k++) {
                if (occur[k][j][0] >= pos[k]) {
                    good = false;
                } else if (occur[k][j][1] >= pos[k]){
                    // do nothing
                } else {
                    msk |= (1 << k);
                }
            }
            if (!good) continue;
            //for (int sm = msk; ; sm--, sm &= msk) {
                //printf("%d %d %d %d\n", vec[i].first, vec[i].second, msk, sm);
                int pre = f[j][msk];
                if (pre + 1 > f[vec[i].first][vec[i].second]) {
                    f[vec[i].first][vec[i].second] = pre + 1;
                    prec[vec[i].first][vec[i].second] = j;
                    prem[vec[i].first][vec[i].second] = msk;
                    if (f[vec[i].first][vec[i].second] > f[bestc][bestm]) {
                        bestc = vec[i].first;
                        bestm = vec[i].second;
                    }
                }
                //if (sm == 0) break;
            //}
        }
        //printf("%d %d %d\n", vec[i].first, vec[i].second, f[vec[i].first][vec[i].second]);
    }
    printf("%d\n", f[bestc][bestm]);
    vector<char> ans;
    while (true) {
        ans.push_back(bestc < 26 ? bestc + 'a' : bestc - 26 + 'A');
        if (f[bestc][bestm] == 1) {
            break;
        } else {
            int c2 = prec[bestc][bestm];
            int m2 = prem[bestc][bestm];
            bestc = c2; bestm = m2;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    /*printf("1\n300000\n");
    for (int i = 1; i <= 300000; i++) {
        printf("%d ", i % 20);
    }*/
    return 0;
}