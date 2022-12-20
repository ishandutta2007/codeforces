// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define sz(c) (c).size()
#define REP(i,n)  for(ll i=0;i<n;i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18,mod=1e9+7;
const ll maxn=2e5+10;

typedef vector< vector<ll> > matrice;

void build_matrice(ll n,ll m,matrice &mat){
	mat.resize(n);
	REP(i,n){
		mat[i].resize(m);
	}
}

void build_one(ll n,matrice &mat){
	mat.resize(n);
	REP(i,n){
		mat[i].resize(n);
		mat[i][i]=1;
	}
}

void build_sp(ll n,matrice &mat){
	mat.resize(n);
	REP(i,n){
		mat[i].resize(n);
		FOR(j,max(ll(0),i-1),min(n-1,i+1))
			mat[i][j]=1;
	}
}
matrice operator*(matrice &a,matrice &b){
	if(sz(a[0])!=sz(b)){
		cerr<<"bad operation!\n";
		exit(0);
	}
	matrice mat;
	build_matrice(sz(a),sz(b[0]),mat);
	REP(i,sz(a)){
		REP(j,sz(b[0])){
			REP(k,sz(a[0])){
				mat[i][j]+=((a[i][k]%mod)*(b[k][j]%mod))%mod;
				mat[i][j]%=mod;
			}
		}
	}
	return mat;
}

matrice power(matrice a,ll b,matrice &one){//matrice should be a square
	if(b==0){
		return one;
	}
	matrice mat=power((a*a),b/2,one);
	if(b%2) return a*mat;
	else return mat;
}

int main(){
	ll n,k;cin>>n>>k;
	matrice mat;build_matrice(1,1,mat);mat[0][0]=1;
	REP(i,n){
		ll a,b,c;cin>>a>>b>>c;
		if(i==n-1){
			b=k;
		}
		matrice New;build_matrice(c+1,1,New);
		REP(j,min(ll(sz(mat)),c+1)){
			New[j][0]=mat[j][0];
		}
		mat=New;
		matrice Pow;build_sp(c+1,Pow);
		matrice one;build_one(c+1,one);
		Pow=power(Pow,b-a,one);
		mat=Pow*mat;
	}
	cout<<mat[0][0];
}