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

const ll alpha=27;
const ll mod=12345;

#pragma GCC Optimize("Ofast")

vector<ll>v[alpha];
ll lc[alpha];
bool vis[alpha];
ll tot=1;
ll cnt[alpha];

void build_sq(matrice &mat,ll num){
	mat.resize(num);
	REP(i,num)
		mat[i].resize(num);
}

matrice operator*(matrice a,matrice b){
	matrice c;
	c.resize(sz(a));
	REP(i,sz(a))
		c[i].resize(sz(b));
	REP(i,sz(a)){
		REP(j,sz(b)){
			REP(k,sz(a[0])){
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j]))%mod;
			}
		}
	}
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

void decode(ll num){
	REP(i,alpha){
		if(!vis[i])continue;
		cnt[i]=num%lc[i];
		num/=lc[i];
	}
}
ll code(){
	ll num=0;
	REPD(i,alpha){
		if(!vis[i])continue;
		num*=lc[i];
		num+=cnt[i];
	}
	return num;
}

matrice build_transition(){
	matrice mat;
	build_sq(mat,tot);
	REP(codes,tot){
		decode(codes);
		REP(i,alpha){
			if(!vis[i])continue;
			cnt[i]=(cnt[i]-1+lc[i])%lc[i];
			mat[codes][code()]++;
			cnt[i]=(cnt[i]+1)%lc[i];
		}
	}
	return mat;
}
matrice build_begin(){
	matrice mat;
	mat.resize(1);
	mat[0].resize(tot);
	REP(i,tot){
		decode(i);
		bool yes=1;
		REP(j,alpha)
			yes&=(cnt[j]==0);
		mat[0][i]=yes;
	}
	return mat;
}

void print(matrice mat){
	REP(i,sz(mat)){
		REP(j,sz(mat[0]))
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
}
int main(){
	ll n,c;cin>>n>>c;
	REP(i,c){
		char ch;
		ll a,b;
		cin>>ch>>b;
		a=ch-'A';
		if(!vis[a]){
			vis[a]=1;
			lc[a]=1;
		}
		v[a].PB(b);
		lc[a]*=b;
		tot*=b;
	}
	matrice mat=build_begin()*Pow(build_transition(),n);
	ll ans=0;
	REP(i,tot){
		decode(i);
		bool final_yes=1;
		REP(j,alpha){
			if(!vis[j])continue;
			bool yes=0;
			REP(k,sz(v[j]))
				yes|=(cnt[j]%v[j][k]==0);
			if(!yes){
				final_yes=0;
				break;
			}
		}
		if(final_yes)
			ans=(ans+mat[0][i])%mod;
	}
	cout<<ans;
}