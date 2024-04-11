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

const ll inf=1e9;
const ll mod=1e9+7;
const ll maxn=1e5+10;

ll a[maxn],b[maxn],n,l=-inf,r=inf;
string s;

void dif1(ll id,ll mn,ll mx){
	l=max(l,mx+1);
}
void dif0(ll id,ll mn,ll mx){
	r=min(r,mn-1);
}
void sam1(ll id,ll mn,ll mx){
	if(b[id]&&b[id-1]&&b[id-2]&&b[id-3]&&b[id-4]){
		r=max(r,mn);
	}
}
void sam0(ll id,ll mn,ll mx){
	if(!b[id]&&!b[id-1]&&!b[id-2]&&!b[id-3]&&!b[id-4]){
		l=min(l,mx);
	}
}

int main(){
	cin>>n;
	REP(i,n)
		cin>>a[i];
	cin>>s;
	
	FOR(i,4,n-1){
		ll mn=inf,mx=-inf;
		REP(j,5){
			mn=min(mn,a[i-j]);
			mx=max(mx,a[i-j]);
		}
		
		if(s[i]!=s[i-1]){
			if(s[i]=='0')
				dif0(i,mn,mx);
			else
				dif1(i,mn,mx);
		}
		else{
			if(s[i]=='0')
				sam0(i,mn,mx);
			else
				sam1(i,mn,mx);
		}
	}
	cout<<l<<" "<<r;
}