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

const ll inf=1e18;
const ll maxn=200;

ll a[maxn],l[maxn];
set<ll>s;
int main(){
	ll n,m;cin>>n>>m;
	fill(a,a+n,-1);
	REP(i,m){
		cin>>l[i];
		l[i]--;
	}
	FOR(i,1,m-1){
		ll num=(((l[i]-l[i-1])%n)+n)%n;
		num=((num==0)?n:num);
		if(a[l[i-1]]!=-1){
			if(num==a[l[i-1]]){
				continue;
			}
			else{
				cout<<-1;
				return 0;
			}
		}
		if(s.count(num)){
			cout<<-1;
			return 0;
		}
		a[l[i-1]]=num;
		s.insert(num);
	}
	ll h=1;
	REP(i,n){
		if(a[i]!=-1)continue;
		while(h<=n&&s.count(h)){
			h++;
		}
		if(h==n+1){
			cout<<-1;
			return 0;
		}
		a[i]=h;
		h++;
	}
	REP(i,n)
		cout<<a[i]<<" ";
}