#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int prf[MAXN], suf[MAXN], ti[MAXN], n, a, b, T;

bool can(int m) {
    if(m == 0)
        return true;
    for(int i = 1; i <= m; i++) {
        int p = i, s = m - i;
        if(prf[p] + suf[n + 1 - s] + a*(m - 1) + a*(p - 1) <= T)
            return true;
        if(prf[p] + suf[n + 1 - s] + a*(m - 1) + a*s <= T)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b >> T;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
        ti[i + 1] = 1 + b * (s[i] == 'w');
    for(int i = 1; i <= n; i++)
        prf[i] = prf[i - 1] + ti[i];
    for(int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + ti[i];
    int lo = 0, hi = n;
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(can(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << '\n';
}