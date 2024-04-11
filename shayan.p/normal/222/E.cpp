// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<vector<ll> > matrice;

const ll maxm=55;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

void build_sq(matrice &mat,ll num){
	mat.resize(num);
	REP(i,num)
		mat[i].resize(num);
}
ll to(char ch){
	if('a'<=ch&&ch<='z')
		return ch-'a';
	return ch-'A'+26;
}
matrice operator*(matrice a,matrice b){
	matrice c;
	c.resize(sz(a));
	REP(i,sz(a))
		c[i].resize(sz(b));
	REP(i,sz(a))
		REP(j,sz(b))
			REP(k,sz(a[0]))
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j]))%mod;
	return c;
}
matrice Pow(matrice a,ll b){
	matrice ans;
	build_sq(ans,sz(a));
	REP(i,sz(a))
		ans[i][i]=1;
	while(b>0){
		if(b%2)
			ans=ans*a;
		a=a*a;
		b/=2;
	}
	return ans;
}

int main(){
	ll n,m,k;cin>>n>>m>>k;
	matrice mat;
	build_sq(mat,m);
	REP(i,m)
		REP(j,m)
			mat[i][j]=1;
	REP(i,k){
		string s;cin>>s;
		mat[to(s[0])][to(s[1])]=0;
	}
	mat=Pow(mat,(n-1));
	ll ans=0;
	REP(i,m)
		REP(j,m)
			ans=(ans+mat[i][j])%mod;
	cout<<ans;
}