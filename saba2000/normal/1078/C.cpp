#include<bits/stdc++.h>
using namespace std;
long long mod=  998244353;
long long dp1[300009],dp2[300009],dp3[300009];
vector<long long> v[300009];
long long f[300009];
void dfs(long long x){
    f[x] = 1;
    dp1[x] = 1;
    dp3[x] = 1;
    vector<long long> l1, l2,l3;
    for (auto y : v[x]){
        if(f[y]) continue;

        dfs(y);
        l1.push_back(dp1[y]);
        l2.push_back(dp2[y]);
        l3.push_back(dp3[y]);
    }
    long long n = l1.size();
    if(n == 0) {dp1[x] = 0;return;}
    for(long long i = 0 ;i  < n; i++)
        dp1[x] = (dp1[x] * (l3[i] + 2*l2[i]) % mod) % mod,
        dp3[x] = (dp3[x] * (l3[i] + l2[i]) % mod) % mod;
    dp1[x]= (dp1[x] - dp3[x] + mod) % mod;
    long long AM = 0, DM = 1;
    for(long long i = 0; i < n; i++){
        long long AM1 = (AM * (l3[i] + 2*l2[i]) % mod + DM * (l1[i] + l3[i]) % mod) % mod;
        long long DM1 = DM * (l3[i] + 2*l2[i]) % mod;
        AM = AM1;
        DM = DM1;
    }
    dp2[x] = AM;

}
main(){
    long long n;
    cin >> n;
    for(long long i =1; i <= n-1; i++){
        long long a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    long long ans = 0;
    cout<<(dp3[1] + dp2[1])% mod<<endl;

}
//