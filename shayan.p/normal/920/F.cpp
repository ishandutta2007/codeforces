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

const ll maxn=3e5+10;
const ll MAX=1e6+10;

#pragma GCC Optimize("Ofast")

set<ll>s;
ll tree[maxn],par[MAX];
int a[maxn];

void add(ll ind,ll x){
	while(ind<maxn){
		tree[ind]+=x;
		ind+=(ind & -ind);
	}
}
ll ask(ll ind){
	ll ans=0;
	while(ind>0){
		ans+=tree[ind];
		ind-=(ind & -ind);
	}
	return ans;
}

ll next(ll num){
	ll ans=1;
	while(num>1){
		ll p=par[num],cnt=0;
		while(num%p==0){
			cnt++;
			num/=p;
		}
		ans*=(cnt+1);
	}
	return ans;
}

int main(){
	
	for(ll i=2;i<MAX;i++){
		if(par[i]==0)
			for(ll j=i;j<MAX;j+=i)
				par[j]=i;
	}
	
	int n,m;scanf("%d%d",&n,&m);
	FOR(i,1,n){
		scanf("%d",&a[i]);
		if(a[i]!=1&&a[i]!=2)
			s.insert(i);
		add(i,a[i]);
	}
	REP(i,m){
		int task,l,r;scanf("%d%d%d",&task,&l,&r);
		if(task==1){
			stack<ll>del=stack<ll>();
			for(set<ll>::iterator it=s.lower_bound(l);it!=s.end()&&(*it)<=r;it++){
				add(*it,-a[*it]);
				a[*it]=next(a[*it]);
				if(a[*it]==1||a[*it]==2)
					del.push(*it);
				add(*it,a[*it]);
			}
			while(sz(del)){
				s.erase(del.top());
				del.pop();
			}
		}
		else{
			cout<<(ask(r)-(l==1?0:ask(l-1)))<<endl;;
		}
	}
}