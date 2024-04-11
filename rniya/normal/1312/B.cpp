#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        int n; cin >> n;
        vector<int> a(n);
        for (int i=0;i<n;++i) cin >> a[i];
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        for (int i=0;i<n;++i) cout << a[i] << (i!=n-1?' ':'\n');
    }
}