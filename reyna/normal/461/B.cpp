//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%I64d",&a)
#define Put(a) printf("%I64d\n",a)
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int Maxn = 1e5 + 1e3;
const ll Mod = 1e9 + 7;
vector<int> al[Maxn];
int bad[Maxn],dp[Maxn][2];
ll pw(ll a,ll b){
    if(!b)
        return 1;
    return (pw((a * a) % Mod,b/2) * (b%2?a:1))%Mod;
}
ll dfs(int v,int p = -1,int state = 1){
    if(dp[v][state] != -1)
        return dp[v][state];
    if(bad[v]){
        if(!state)
            return 0;
        ll ret = 1;
        For(i,0,al[v].size()){
            int u = al[v][i];
            if(u == p)
                continue;
            ret *= (dfs(u,v,0) + dfs(u,v,1));
            ret %= Mod;
        }
        return dp[v][state] = ret;
    }
    ll ret = 1;
    For(i,0,al[v].size()){
        int u = al[v][i];
        if(u == p)
            continue;
        ret *= (dfs(u,v,1) + dfs(u,v,0));
        ret %= Mod;
    }
    if(!state)
        return dp[v][state] = ret;
    ll res = 0;
    For(i,0,al[v].size()){
        int u = al[v][i];
        if(u == p)
            continue;
        ll div = dfs(u,v,1) + dfs(u,v,0);
        div %= Mod;
        res += (((ret * pw(div,Mod-2)) % Mod) * dfs(u,v,1))% Mod;
        res %= Mod;
    }
    return dp[v][state] = res;
}
int main(){
    int n;
    cin >> n;
    For(i,0,n-1){
        int now;
        cin >> now;
        al[now].push_back(i+1);
        al[i+1].push_back(now);
    }
    For(i,0,n){
        cin >> bad[i];
    }
    memset(dp,-1,sizeof dp);
    cout << dfs(0) << endl;
    return 0;
}