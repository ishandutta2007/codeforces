#include <bits/stdc++.h>
#define FOR(i,l,r) for(int i=1; i<=r; ++i)
#define REP(i,l,r) for(int i=1; i<r; ++i)
using namespace std;
const int N = 100005;
int t, n, x, odd, even, a[N], f[N];

void Enter() {
}

void Process() {
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        odd = even = 0;
        for(int i=1; i<=n*2; ++i) {
            cin >> x;
            if (x&1) ++odd; else ++even;
        }
        if (odd == even) cout << "Yes\n"; else cout << "No\n";
    }
}