// Remember...

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

const int maxn=2010 ,mod=998244353;
const ll inf=1e18;

int C[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    for(int i=0;i<maxn;i++){
	C[i][0] = C[i][i] =1;
	for(int j=1;j<i;j++)
	    C[i][j]=(C[i-1][j] + C[i-1][j-1]) %mod;
    }
    string s; cin>>s;
    int n=sz(s);
    
    int ans=0;
    
    for(int c=1; c<=n; c++){
	int num=0;
	pii A={0,0}, B={0,0};
	for(int i=0;i<n;i++){
	    if(s[i]=='?')
		B.F++;
	    if(s[i]==')')
		B.S++;		
	}
	for(int i=0;i<n;i++){
	    if(s[i]=='?')
		B.F--, A.F++;
	    if(s[i]==')')
		B.S--;
	    if(s[i]=='(')
		A.S++;
	    if(c>=B.S && c>=A.S)
		num= ( 1ll*num + 1ll* C[A.F][c - A.S] * C[B.F][c - B.S] ) %mod;
	}
	ans = ( 1ll*ans + 1ll*c * num ) %mod;
    }
    if(ans<0)
	ans+=mod;
    return cout<<ans<<endl,0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")