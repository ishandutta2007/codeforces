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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll p[maxn],s[maxn];
ll n,m;
map<ll,vector<ll> >mp;
ll adap[maxn];// number of adapter for a certain soket
ll con[maxn];// index of adapter which i th computer connects to
bool mark[maxn];// if an adapter is used
ll c,u;

int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>p[i];
		mp[p[i]].PB(i);
	}
	REP(i,m){
		cin>>s[i];
	}
	ll tw=1;
	REP(q,31){
		REP(i,m){
			if(mark[i])
				continue;
			//changed s[i]
			if(mp.count(s[i])&&!mp[s[i]].empty()){// now connect
				ll ind=mp[s[i]].back();
				mp[s[i]].POB();
				con[ind]=i+1;
				adap[i]=q;
				mark[i]=1;
				c++;
				u+=q;
			}
			s[i]=(s[i]/2)+(s[i]%2);
		}
	}
	cout<<c<<" "<<u<<endl;
	REP(i,m)
		cout<<adap[i]<<" ";
	cout<<endl;
	REP(i,n)
		cout<<con[i]<<" ";
}