// https://codeforces.com/contest/1392/problem/A
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 200005;
LL a[SZ], b[SZ];

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int n; LL k; cin>>n>>k;
        for (int i = 0; i < n; i++)
            cin>>a[i];
        int mx = *max_element(a, a+n);
        for (int i = 0; i < n; i++)
            b[i] = mx - a[i];
        mx = *max_element(b, b+n);
        for (int i = 0; i < n; i++)
            a[i] = mx - b[i];
        LL *ans = ((k&1) ? b : a);
        for (int i = 0; i < n; i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}