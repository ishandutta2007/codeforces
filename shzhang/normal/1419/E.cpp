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

int pf[1005];
int ex[1005];
int nxt_pf = 1;

void search(int curv, int idx, bool allow_zero, vector<int>& ans)
{
    if (idx == nxt_pf) {
        ans.push_back(curv); return;
    }
    if (!allow_zero) curv *= pf[idx];
    for (int i = (allow_zero ? 0 : 1); i <= ex[idx]; i++) {
        search(curv, idx + 1, true, ans);
        if (i != ex[idx]) curv *= pf[idx];
    }
}

void work()
{
    int n; scanf("%d", &n);
    nxt_pf = 1;
    int bound = n;
    for (int i = 2; i * i <= bound; i++) {
        if (n % i == 0) {
            pf[nxt_pf] = i; ex[nxt_pf] = 0;
            while (n % i == 0) {
                n /= i; ex[nxt_pf]++;
            }
            nxt_pf++;
        }
    }
    if (n != 1) {
        pf[nxt_pf] = n; ex[nxt_pf] = 1;
        nxt_pf++;
    }
    if (nxt_pf == 3 && ex[1] == ex[2] && ex[1] == 1) {
        printf("%d %d %d\n1\n", pf[1], pf[2], pf[1] * pf[2]); return;
    }
    if (nxt_pf == 2) {
        int cur = pf[1];
        for (int i = 1; i <= ex[1]; i++) {
            printf("%d ", cur);
            if (i != ex[1]) cur *= pf[1];
        }
        printf("\n0\n"); return;
    }
    vector<int> ans;
    for (int i = 1; i < nxt_pf; i++) {
        search(1, i, false, ans);
    }
    int rem_val = pf[1] * pf[nxt_pf - 1];
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != rem_val) printf("%d ", ans[i]);
    }
    printf("%d\n0\n", rem_val);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}