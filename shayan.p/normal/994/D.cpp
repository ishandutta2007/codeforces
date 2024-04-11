// new day,new strength,new thougts
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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=31;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

pll pa[maxn],pb[maxn];
set<ll>sa[maxn],sb[maxn],s;

ll ask(pll a,pll b){
	if(a.F>a.S)swap(a.F,a.S);
	if(b.F>b.S)swap(b.F,b.S);
	if(a==b)return -1;
	if(a.F==b.F)return a.F;
	if(a.F==b.S)return a.F;
	if(a.S==b.F)return a.S;
	if(a.S==b.S)return a.S;
	return -1;
}

int main(){
	ll n,m;cin>>n>>m;
	REP(i,n)
		cin>>pa[i].F>>pa[i].S;
	REP(i,m)
		cin>>pb[i].F>>pb[i].S;
	REP(i,n){
		REP(j,m){
			ll num=ask(pa[i],pb[j]);
			if(num==-1)continue;
			sa[i].insert(num);
			sb[j].insert(num);
			s.insert(num);
		}
	}
	if(sz(s)==1){
		cout<<(*s.begin());
		return 0;
	}
	REP(i,n){
		if(sz(sa[i])>1){
			cout<<-1;
			return 0;
		}
	}
	REP(i,m){
		if(sz(sb[i])>1){
			cout<<-1;
			return 0;
		}
	}
	cout<<0;
}