// only miss the sun when it starts to snow

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)
#define REP(i,n) for(i=0;i<n;i++)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int maxn= 66, mod=998244353;// too strict

set<string> s[20][maxn];
int adj[maxn][maxn];
int f[maxn][maxn][maxn];

int pos[10], cf[2][2][2];

inline int code(char ch){
    if( 'a'<=ch && ch<='z' ) return ch - 'a';
    if( 'A'<=ch && ch<='Z' ) return ch - 'A' + 26;
    return ch - '0' + 26 + 26;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    cf[0][0][0]= 24;
    cf[0][0][1]= 12;
    cf[0][1][0]= 12;
    cf[1][0][0]= 12;
    cf[0][1][1]= 4;
    cf[1][1][0]= 4;
    cf[1][0][1]= 6;
    cf[1][1][1]= 1;
    
    int n; cin>>n;

    while(n--){
	string ss; cin>>ss;

	s[sz(ss)][ code(ss[0]) ].insert(ss);
	reverse(ss.begin(), ss.end() );
	s[sz(ss)][ code(ss[0]) ].insert(ss);
    }
    int ans=0;
    for(int ln=3;ln<=10;ln++){
	memset(adj,0,sizeof adj);
	memset(f,0,sizeof f);

	for(int i=0;i<maxn;i++){
	    for(auto &ss:s[ln][i]){
		adj[i][ code(ss.back()) ]++;
	    }
	}
	for(int i=0;i<maxn;i++){
	    for(int j=i;j<maxn;j++){
		for(int k=j;k<maxn;k++){
		    int sum=0;
		    for(int w=0;w<maxn;w++)
			sum= (1ll*sum + 1ll*adj[i][w] *adj[j][w] *adj[k][w]) %mod;
		    f[i][j][k]= f[i][k][j]= f[j][i][k]= f[j][k][i]= f[k][i][j]= f[k][j][i]= sum;
		}
	    }
	}
	
	for(int i=0;i<maxn;i++){
	    for(int j=i;j<maxn;j++){
		for(int k=j;k<maxn;k++){
		    for(int w=k;w<maxn;w++){
			ans= (1ll*ans + 1ll*f[i][j][k] *f[i][j][w] %mod *f[i][k][w] %mod *f[j][k][w] %mod *cf[i==j][j==k][k==w]) %mod;
		    }
		}
	    }
	}
    }
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem curfully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")