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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=1e18;
const ll maxn=1e6+10;

map<ll,int>last;
ll val[maxn];
int aft[maxn],bef[maxn];
ll a[maxn];

void add(int ind,int x){
	while(ind<maxn){
		val[ind]+=x;
		ind+=(ind & -ind);
	}
}
ll ask(int ind){
	ll ans=0;
	while(ind>0){
		ans+=val[ind];
		ind-=(ind & -ind);
	}
	return ans;
}

int main(){
	int n;scanf("%d",&n);
	REP(i,n){
		scanf("%lld",&a[i]);
	}
	REP(i,n){
		bef[i]=(last.count(a[i])?bef[last[a[i]]]:0)+1;
		last[a[i]]=i;
	}
	last.clear();
	REPD(i,n){
		aft[i]=(last.count(a[i])?aft[last[a[i]]]:0)+1;
		last[a[i]]=i;
	}
	REP(i,n){
		add(aft[i],1);
	}
	ll ans=0;
	REP(i,n){
		add(aft[i],-1);
		ans+=ask(bef[i]-1);
	}
	cout<<ans;
}