#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n),cnt(n,0);
        for (int i=0;i<n;++i) cin >> a[i],--a[i];
        int ok=0;
        for (int i=n-1;i>=0;--i){
            if (cnt[a[i]]) ok=1;
            if (i<n-1) ++cnt[a[i+1]];
        }
        cout << (ok?"YES":"NO") << '\n';
    }
}