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
const ll maxn=1e5+10;

ll a[maxn],b[maxn];
vector<ll>v[4*maxn];
ll n,k;
deque<ll> last[maxn];

void merge(vector<ll>&g,vector<ll>v1,vector<ll>&v2){
	ll h1=0,h2=0;
	REP(i,sz(v1)+sz(v2)){
		if(h1==sz(v1)){
			g.PB(v2[h2++]);
		}
		else if(h2==sz(v2)){
			g.PB(v1[h1++]);
		}
		else{
			if(v1[h1]<v2[h2]){
				g.PB(v1[h1++]);
			}
			else{
				g.PB(v2[h2++]);
			}
		}
	}
}
ll bound(ll num,vector<ll>&vec){
	ll l=0,r=sz(vec)-1,ans=sz(vec);
	while(l<=r){
		ll mid=(l+r)/2;
		if(vec[mid]<num){
			l=mid+1;
		}
		else{
			ans=mid;
			r=mid-1;
		}
	}
	return ans;
}
void build(ll l=1,ll r=n,ll ind=1){
	if(l==r){
		v[ind].PB(b[l]);
		return;
	}
	ll mid=(l+r)/2;
	build(l,mid,2*ind);
	build(mid+1,r,2*ind+1);
	merge(v[ind],v[2*ind],v[2*ind+1]);
}
ll ask(ll f,ll s,ll l=1,ll r=n,ll ind=1){
	if(s<l||r<f)return 0;
	if(f<=l&&r<=s){
		return bound(f,v[ind]);
	}
	ll mid=(l+r)/2;
	return ask(f,s,l,mid,2*ind)+ask(f,s,mid+1,r,2*ind+1);
}
int main(){
	cin>>n>>k;
	FOR(i,1,n){
		ll x;cin>>x;
		if(sz(last[x])<k){
			last[x].PB(i);
		}
		else{
			b[i]=last[x][0];
			last[x].POF();
			last[x].PB(i);
		}
	}
	build();
	ll q;cin>>q;
	ll last=0;
	REP(i,q){
		ll l,r;cin>>l>>r;
		l=((last+l)%n)+1;
		r=((last+r)%n)+1;
		if(l>r)swap(l,r);
		cout<<(last=ask(l,r))<<endl;
	}
}