#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, k, A, B;
int a[N];

ll solve(int l, int r, int tl, int tr) {
    if(l == r) return A;
    int tm = (tl + tr) / 2;
    ll res = 1LL * (r - l) * (tr - tl + 1) * B;
    if(tl == tr) return res;
    int mid = lower_bound(a + l, a + r, tm + 1) - a;
    res =  min(res, solve(l, mid, tl, tm) + solve(mid, r, tm + 1, tr));
    return res;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &A, &B);
    for(int i = 0; i < k; i++) scanf("%d", &a[i]), a[i] --;
    sort(a, a + k);
    ll res = solve(0, k, 0, (1 << n) - 1);
    cout << res << endl;
}