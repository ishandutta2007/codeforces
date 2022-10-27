#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
using namespace std;
const int N=200000+10;
int n,par[N],leaf;
LL p[N],cnt[N],ways[N],f[N][2];

LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}

vector<int> g[N];
void dfs(int u){
    if(g[u].size()==0) {
        leaf++; f[u][0]=f[u][1]=1;return;
    }   
    LL mul=1;
    LL mul1=1;

    for(auto v:g[u]){
        dfs(v); 
        mul=mul*(f[v][0]+f[v][1])%MOD;
        mul1=mul1*f[v][1]%MOD;
    }
    f[u][0]=((mul-mul1)%MOD+MOD)%MOD;
    for(auto v:g[u]){
        mul=mul-f[v][0]*mul1%MOD*mpow(f[v][1],MOD-2)%MOD; mul=(mul%MOD+MOD)%MOD;
    }
    f[u][1]=mul; 
}

int main(){
    p[0]=1; for(int i=1;i<N;i++)p[i]=p[i-1]*2%MOD;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int x; scanf("%d",&x); g[x].push_back(i);
    }
    dfs(1);
    cout<<f[1][1]<<endl;
}

/*
[1,n]
[l,r]

(2^(l-1)-1)*(2^(n-r)-1)
2^(n-1-(r-l)) - 2^(l-1) - 2^(n-r) + 1
l+n-r-1
*/