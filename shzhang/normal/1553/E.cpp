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

int n, m;
int p[300005];
int off[300005];
int freq[300005];
int p2[300005];
bool mark[300005];

bool check(int k)
{
    //printf("check %d\n", k);
    for (int i = 0; i < n; i++) {
        p2[i] = (p[i] + k) % n; mark[i] = false;
    }
    /*for (int i = 0; i < n; i++) {
        printf("%d ", p2[i]);
    }
    printf("\n");*/
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (mark[i]) continue;
        int cur = i; int len = 0;
        do {
            len++; cur = p2[cur]; mark[cur] = true;
        } while (cur != i);
        cnt += len - 1;
    }
    //printf("! %d\n", cnt);
    return cnt <= m;
}

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", p + i); p[i]--;
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        off[i] = (i + n - p[i]) % n;
        freq[off[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        //printf("%d ", freq[i]);
        if (n - freq[i] <= 2 * m) {
            if (check(i)) ans.push_back(i);
        }
    }
    printf("%d ", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}