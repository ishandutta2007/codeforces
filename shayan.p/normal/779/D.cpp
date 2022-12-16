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

const ll inf=4e18;
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll p[maxn];
bool mark[maxn];
string a,b;

bool pos(ll ind){
	memset(mark,0,sizeof mark);
	REP(i,ind)
		mark[p[i]-1]=1;
	ll lst=0;//last unused
	REP(i,sz(b)){
		while(lst<sz(a)&&(mark[lst]||b[i]!=a[lst]))
			lst++;
		if(lst==sz(a))
			return 0;
		lst++;
	}
	return 1;
}
int main(){
	cin>>a>>b;
	REP(i,sz(a))
		cin>>p[i];
	ll l=0,r=sz(a),ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(pos(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
}