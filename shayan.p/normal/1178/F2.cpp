// only miss the sun when it starts to snow

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn=510, Max=1e6+10, mod=998244353;

vector<int> v[maxn];
int dp[2*maxn][maxn], df[2*maxn], C;
int a[Max];

int solve(int l,int r);
void solve2(int l,int r,int id);

int solve(int l,int r){
    if(r-l<=0) return 1;
    
    int mn=maxn;
    for(int i=l;i<r;i++){
	mn=min(mn, a[i]);
    }
    if(v[mn][0]<l || r<=v[mn].back()) cout<<0<<endl, exit(0);

    int ans=1;
    for(int i=0;i<sz(v[mn])-1;i++){
	ans= 1ll*ans* solve(v[mn][i]+1, v[mn][i+1]) %mod;
    }
    int id1=C++, id2=C++;

    solve2(l,v[mn][0],id1), solve2(v[mn].back() + 1,r, id2);

    int num=0;
    
    for(int i=0;i<=df[id1];i++){
	for(int j=0;j<=df[id2];j++){
	    num=(1ll*num + 1ll*dp[id1][i] * dp[id2][j] %mod *(i+1) %mod *(j+1) )%mod;
	}
    }
    return 1ll*ans*num %mod;
}
void solve2(int l,int r,int id){
    if(r-l<=0){
	dp[id][0]=1;
	return;
    }
    
    int mn=maxn;
    for(int i=l;i<r;i++){
	mn=min(mn, a[i]);
    }
    if(v[mn][0]<l || r<=v[mn].back()) cout<<0<<endl, exit(0);

    int ans=1;
    for(int i=0;i<sz(v[mn])-1;i++){
	ans= 1ll*ans* solve(v[mn][i]+1, v[mn][i+1]) %mod;
    }
    int id1=C++, id2=C++;

    solve2(l,v[mn][0],id1), solve2(v[mn].back() + 1,r, id2);

    df[id]= df[id1] + df[id2] + 1;
    
    for(int i=0;i<=df[id1];i++){
	for(int j=0;j<=df[id2];j++){
	    int num= 1ll*dp[id1][i] *dp[id2][j] %mod;
	    for(int k=0;k<=i+j;k++){
		dp[id][k+1]=(1ll*dp[id][k+1] + 1ll*num * max(int(0), min(i,k) - max(k-j,0) +1) )%mod;
	    }
	}
    }
    for(int i=0;i<=df[id];i++){
	dp[id][i]= 1ll* dp[id][i] * ans %mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    int n,m; cin>>n>>m;

    for(int i=0;i<m;i++){
	cin>>a[i];
	v[--a[i]].PB(i);
    }
    return cout<<solve(0,m)<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")