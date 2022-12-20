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
#define REP(i,n)  for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=52;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

string g[maxn];
bool used[maxn];

bool bad(ll id){
	REP(i,sz(g[id]))
		if(g[id][i]=='#')
			return 1;
	return 0;
}

int main(){
	ll n,m;cin>>n>>m;
	REP(i,n)
		cin>>g[i];
	REP(i,n){
		if(used[i]){
			if(bad(i)){
				cout<<"No";
				return 0;
			}
			else{
				continue;
			}
		}
		vector<ll>v;
		v.clear();
		REP(j,m){
			if(g[i][j]=='#')
				v.PB(j);
		}
		FOR(k,i,(n-1)){
			if(used[k])
				continue;
			ll cnt0=0,cnt1=0;
			REP(j,sz(v)){
				if(g[k][v[j]]=='.')
					cnt0++;
				else
					cnt1++;
			}
			if(cnt0==sz(v)){
			}
			else if(cnt1==sz(v)){
				used[k]=1;
				REP(j,sz(v))
					g[k][v[j]]='.';
			}
			else{
				cout<<"No";
				return 0;
			}
		}
	}
	cout<<"Yes";
}