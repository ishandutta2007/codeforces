#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    int dpa[n+1];
    int dpab[n+1];
    int dpabc[n+1];
    dpa[0] = dpab[0] = dpabc[0] = 0;
    int kekw = 1;
    for (int i=1; i <= n; i++) {
        dpa[i]=0;
        dpab[i]=0;
        dpabc[i]=0;
        if (s[i] != '?') {
            dpa[i] = dpa[i-1] + (s[i]=='a')*kekw;
            dpab[i]=dpab[i-1]+((s[i]=='b')*dpa[i-1]);
            dpabc[i]=dpabc[i-1]+((s[i]=='c')*dpab[i-1]);
        } else {
            dpa[i] = 3*dpa[i-1] + kekw;
            dpab[i]=3*dpab[i-1]+dpa[i-1];
            dpabc[i]=3*dpabc[i-1]+dpab[i-1];
            kekw *= 3;
            kekw %= M;
        }
        dpa[i] %= M;
        dpab[i] %= M;
        dpabc[i] %= M;
    }
    cout << dpabc[n] << '\n';
}