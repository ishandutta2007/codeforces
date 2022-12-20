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
const ll maxn=1e5+10;

ll seg1[maxn],seg2[maxn];// forward , backward

int main(){
	string a,b;cin>>a>>b;
	ll last=0;//last unused
	REP(i,sz(b)){
		while(last<sz(a)&&a[last]!=b[i])
			last++;
		seg1[i]=last;
		if(last!=sz(a))
			last++;
	}
	last=sz(a)-1;
	REPD(i,sz(b)){
		while(last>=0&&a[last]!=b[i])
			last--;
		seg2[i]=last;
		if(last!=-1)
			last--;
	}
		
	ll r=0;
	ll L=-1,R=sz(b);// ()
	while(r<sz(b)&&0>seg2[r])
		r++;
	R=r;
	REP(l,sz(b)){
		r=max(r,l+1);
		while(r<sz(b)&&seg1[l]>=seg2[r])
			r++;
		if(((r==sz(b)&&seg1[l]<sz(a))||seg1[l]<seg2[r])&&(R-L)>(r-l)){
			R=r;
			L=l;
		}
	}
	if(L==-1&&R==sz(b))
		cout<<"-";
	else{
		FOR(i,0,L)
			cout<<b[i];
		FOR(i,R,sz(b)-1)
			cout<<b[i];
	}
}