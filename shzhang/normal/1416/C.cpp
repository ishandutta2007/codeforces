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

ll final_invs = 0;
int ans = 0;

void work(vector<int>& a, int bit)
{
    int n = a.size();
    //for (int i = 0; i < n; i++) printf("%d ", a[i]);
    //printf("\n");
    ll invs = 0; ll antiinvs = 0;
    ll zeros = 0; ll ones = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            zeros = 0; ones = 0;
        } else if (a[i] & (1 << bit)) {
            ones++; antiinvs += zeros;
        } else {
            zeros++; invs += ones;
        }
    }
    if (antiinvs < invs) {
        ans |= (1 << bit);
        final_invs += antiinvs;
    } else {
        final_invs += invs;
    }
    vector<int> newa;
    for (int i = 0; i < n; i++) {
        if (a[i] != -1) continue;
        newa.push_back(-1);
        for (int j = i + 1; j < n && a[j] != -1; j++) {
            if (a[j] & (1 << bit)) newa.push_back(a[j]);
        }
        newa.push_back(-1);
        for (int j = i + 1; j < n && a[j] != -1; j++) {
            if (!(a[j] & (1 << bit))) newa.push_back(a[j]);
        }
    }
    vector<int> newa2;
    for (int i = 0; i < newa.size(); i++) {
        if (i >= 1 && newa[i] == -1 && newa[i-1] == -1) continue;
        newa2.push_back(newa[i]);
    }
    if (bit) work(newa2, bit - 1);
}

int main()
{
    vector<int> a;
    int n; scanf("%d", &n);
    a.push_back(-1);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a.push_back(x);
    }
    work(a, 30);
    printf("%lld %d", final_invs, ans);
    return 0;
}