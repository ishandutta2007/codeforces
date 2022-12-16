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

#pragma GCC Optimize("Ofast")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll maxn=2e5+10;

map<ll,ll>mp;

int main(){
	ll n,k;cin>>n>>k;
	ll now=0;
	ll sm=0;
	while(n>0){
		if(n%2)
			mp[now]=1;
		sm+=(n%2);
		n/=2;
		now++;
	}
	if(sm>k){
		cout<<"No";
		return 0;
	}
	while(sm<k){
		pll p=*mp.rbegin();
		if((p.S)<=(k-sm)){
			mp[p.F-1]+=(2*p.S);
			mp.erase(p.F);
			sm+=(p.S);
		}
		else{
			while(sm<k){
				pll t=*mp.begin();
				if(--mp[t.F]==0)
					mp.erase(t.F);
				mp[t.F-1]+=2;
				sm++;
			}
		}
	}
	cout<<"Yes\n";
	for(map<ll,ll>::reverse_iterator it=mp.rbegin();it!=mp.rend();it++){
		REP(i,(it->S))
			cout<<it->F<<" ";
	}
}