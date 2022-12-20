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

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=510;

#pragma GCC Optimize("Ofast")

ll ans[maxn][maxn];// i // k
ll sm[maxn][maxn];
ll n,m,k;

void calc(ll ind,string &s){
	vector<ll>v;
	v.clear();
	REP(i,sz(s)){
		if(s[i]=='1')
			v.PB(i);
	}
	if(sz(v)==0)
		return;
	FOR(i,0,min(k,ll(sz(v)))){
		ll mn=inf;
		ll ln=sz(v)-i;
		if(ln==0)
			mn=0;
		else{
			FOR(j,0,sz(v)-ln){
				mn=min(mn,v[j+ln-1]-v[j]+1);
			}
		}
		ans[ind][i]=mn;
	}
}

int main(){
	cin>>n>>m>>k;
	FOR(i,1,n){
		string s;cin>>s;
		calc(i,s);
	}
	FOR(i,1,n){
		FOR(j,0,k){
			sm[i][j]=inf;
			FOR(ch,0,j){
				sm[i][j]=min(sm[i][j],sm[i-1][ch]+ans[i][j-ch]);
			}
		}
	}
	cout<<sm[n][k];
}