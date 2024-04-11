#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#define ll long long

int n;
ll wt[200005];
int sortseq[200005];
ll sellseq[200005];
ll p[200005];
int x, a, y, b;
ll k;

bool cmp(ll A, ll B)
{
    return A > B;
}

bool check(int tickets)
{
    vector<int> wts;
    for (int i = 1; i <= tickets; i++) wts.push_back(wt[i]);
    sort(wts.begin(), wts.end(), cmp);
    ll amt = 0;
    for (int i = 1; i <= tickets; i++) amt += (p[i] * wts[i-1]) / 100LL;
    return amt >= k;
}

int main()
{
    int q;
    scanf("%d", &q);
    for (int data = 1; data <= q; data++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", p + i);
        }
        sort(p + 1, p + n + 1, cmp);
        scanf("%d%d%d%d", &x, &a, &y, &b);
        for (int i = 1; i <= n; i++) wt[i] = 0;
        for (int i = a; i <= n; i += a) wt[i] += x;
        for (int i = b; i <= n; i += b) wt[i] += y;
        int l = 1, r = n;
        scanf("%lld", &k);
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (!check(n)) {
            printf("-1\n");
        } else {
            printf("%d\n", l);
        }
    }
    return 0;
}
//