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
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

ll a[maxn];
pll arr[maxn];
ll n;

struct Lis{
	stack<pair<ll,pll> >s;// ans, point update
	ll lst[maxn],ans;
	Lis(){
		fill(lst,lst+maxn,inf);
		lst[0]=-inf;
		ans=0;
	}
	ll add(ll x){
		ll ind=upper_bound(lst,lst+maxn,x)-lst;
		s.push(MP(ans,MP(ind,lst[ind])));
		lst[ind]=x;
		ans=max(ans,ind);
	}
	void undo(){
		pair<ll,pll>p=s.top();
		s.pop();
		ans=p.F;
		lst[p.S.F]=p.S.S;
	}
};Lis lis[2];

int main(){
	cin>>n;
	REP(i,n){
		cin>>a[i];
		a[i]-=i;
	}
	REPD(i,n)
		lis[1].add(-a[i]-1);
		
	lis[1].undo();
	lis[0].add(a[0]);
	
	ll Ans=n-1-lis[1].ans;
	FOR(i,1,n-1){// or n-2
		lis[1].undo();
		Ans=min(Ans,n-1-ll(upper_bound(lis[0].lst,lis[0].lst+maxn,a[i-1])-lis[0].lst-1  +  upper_bound(lis[1].lst,lis[1].lst+maxn,(-a[i-1]))-lis[1].lst-1));
//		cout<<upper_bound(lis[0].lst,lis[0].lst+maxn,a[i-1])-lis[0].lst<<" "<<upper_bound(lis[1].lst,lis[1].lst+maxn,(-a[i-1]))-lis[1].lst<<endl;
		lis[0].add(a[i]);
	}
	cout<<Ans;
}