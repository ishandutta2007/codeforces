#include<bits/stdc++.h>
using namespace std;
int p[500009],f[1000009];
void solve(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        f[p[i]]++;
    }
    vector<int> v;
    for(int i = 1; i <= n; i++){
        if(i > 1 && p[i] == p[i-1]) continue;
        v.push_back(f[p[i]]);
    }
    for(int i = 1; i <= n; i++){
        f[p[i]]=0;
    }
    if(v.size() < 4){
        cout<<0<<" "<<0<<" "<<0<<endl;
        return;
    }
    int g = v[0],s = 0,b=0;
    int i = 1;
    while(i < v.size() && s <= g) s += v[i], i++;
    while(i < v.size() && b <= g) b += v[i], i++;
    while(i < v.size() && (s+b+g+v[i])<=n/2) b+=v[i], i++;
    if(s && b && g && (s+b+g)<=n/2 && s > g && b > g){
        cout<<g<<" "<<s<<" "<<b<<endl;
        return;
    }
    cout<<0<<" "<<0<<" "<<0<<endl;

}
main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}