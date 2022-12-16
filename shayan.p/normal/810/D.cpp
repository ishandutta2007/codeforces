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
const ll maxn=2e5+10;
ll n,k;
inline bool Ask(ll x,ll y){
	cout<<"1 "<<x<<" "<<y<<endl;
	string s;cin>>s;
	return (s=="TAK");
}
inline void Ans(ll x,ll y){
	cout<<"2 "<<x<<" "<<y<<endl;
}
ll Find(ll l,ll r,bool act){//act: 1:look forward   0:look backward
	while(l<r){
		ll mid;
		if(act){
			mid=(l+r)/2-((l%2)==(r%2));// if we have an odd block
			if(Ask(mid+1,mid)){//go forward
				l=mid+1;
			}
			else{ //go backward
				r=mid;
			}
		}
		else{
			mid=((l+r)/2)-((l%2)==(r%2));//if we have an odd block
			if(Ask(mid,mid+1)){//go backward
				r=mid;
			}
			else{//go forward
				l=mid+1;
			}
		}
	}
	//now l==r
	return l;
}
int main(){
	ll n,k;cin>>n>>k;
	ll ans1=Find(1,n,1);
	ll ans2=Find(ans1+1,n,1);
	ll ans3=Find(1,ans1-1,0);
	if(0<ans2&&ans2<=n&&Ask(ans2,ans1)==Ask(ans1,ans2)) Ans(ans1,ans2);
	else Ans(ans1,ans3);
}