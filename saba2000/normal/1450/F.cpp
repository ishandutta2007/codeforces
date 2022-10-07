#include<bits/stdc++.h>
using namespace std;
int a[300009],f[300009],g[300009],h[300009];
void solve(int n){
    for(int i =1 ;i <= n; i++){
        cin >> a[i];
        f[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        if(f[i] - (n - f[i]) > 1){
            cout << -1 << endl;
            return;
        }
    }
    int st = a[1];
    vector<pair<int,int> > v;
    for(int i = 2; i <= n; i++){
        if(a[i] == a[i-1]){
            v.push_back({st, a[i-1]});
            st = a[i];
        }
    }
    v.push_back({st, a[n]});
    for(auto S : v){
        if(S.first == S.second) g[S.first]++;
        else{
            h[S.first]++;
            h[S.second]++;
        }
    }
    int mx = 0;
    for(int i = 1; i <= n; i++){
        mx = max(mx, 2*g[i] + h[i] - (int)v.size()-1);
    }
    cout << (int)v.size() - 1 + mx <<endl;

}
main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
        for(int i = 1; i <= n; i++){
            a[i] = 0;
            f[i]  =0;
            g[i] = 0;
            h[i] = 0;
        }
    }
}