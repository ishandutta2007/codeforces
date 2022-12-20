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

const ll mod=1e9+7;
const ll inf=4e18;
const ll maxn=1e4+10;

#pragma GCC Optimize("Ofast")

matrice mats[9];
vector<pll>obs;
ll n,m;

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

void build_mats(){
	build_sq(mats[0],3);
	REP(i,3){
		REP(j,3){
			mats[0][i][j]=1;
		}
	}
	mats[0][0][2]=mats[0][2][0]=0;
	FOR(i,1,7){
		mats[i]=mats[0];
		REP(b,3){
			if(bit(i,b)){
				REP(j,3){
					mats[i][j][b]=0;
				}
			}
		}
	}
}

void merge(vector<pll>&v){
	vector<pll>vec;vec.clear();
	sort(v.begin(),v.end());
	ll pt=0;
	while(pt<sz(v)){
		ll beg=v[pt].F,lst=v[pt].S;
		pt++;
		while(pt<sz(v)&&v[pt].F<=lst){
			lst=max(lst,v[pt].S);
			pt++;
		}
		vec.PB(MP(beg,lst));
	}
	v=vec;
}

void input(){
	cin>>n>>m;
	vector<pll>vec[3];
	REP(i,n){
		ll a,l,r;cin>>a>>l>>r;
		a--;l--;r--;
		vec[a].PB(MP(l,r));
	}
	REP(i,3){
		merge(vec[i]);
		REP(j,sz(vec[i])){
			obs.PB(MP(vec[i][j].F,i));
			obs.PB(MP(vec[i][j].S+1,i));
		}
	}
	obs.PB(MP(m,0));
	sort(obs.begin(),obs.end());
}

int main(){
	build_mats();
	input();
	matrice dp;
	dp.resize(1);
	dp[0].resize(3);
	dp[0][1]=1;
	ll nw=0,msk=0;
	REP(i,sz(obs)){
		dp=dp*Pow(mats[msk],obs[i].F-nw-1);
		msk^=(1<<(obs[i].S));
		nw=obs[i].F-1;
	}
	cout<<dp[0][1];
}