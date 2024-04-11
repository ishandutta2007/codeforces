
#include<bits/stdc++.h>
using namespace std;
long long b[100009];
vector<int> v[100090];
long long mod = 1e9+7;
long long ans = 0 ;
void dfs(int x, vector<pair<long long,long long>  > u, int p){

    vector<pair<long long,long long>  > V;
    ans =(ans + b[x]) % mod;
    V.push_back({1,b[x]});
    for(int i = 0; i < u.size(); i++){
        long long K = __gcd(b[x], u[i].second);
        ans = (ans  + u[i].first * K)% mod;
        if(K == V.back().second) V.back().first+= u[i].first;
        else V.push_back({u[i].first, K});
    }
    for(int y : v[x]){
        if(y != p) dfs(y,V,x);
    }
}
main(){
    int n ;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin >>b[i];
    for(int i = 1; i <= n -1; i++){
        int a,b;
        cin >> a >>b;
        v[a].push_back(b );
        v[b].push_back(a);


    }
    dfs(1,{},0);
    cout<<ans<<endl;
}