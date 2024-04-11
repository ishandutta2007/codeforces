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
const ll maxn=3e5+10;

char ans[maxn];

int main(){
	multiset<char> mp1,mp2;
	string s1,s2;cin>>s1>>s2;
	ll n=sz(s1);
	REP(i,n)
		mp1.insert(s1[i]);
	REP(i,n)
		mp2.insert(s2[i]);
	while(sz(mp1)>((n/2)+(n%2))){
		mp1.erase(--mp1.end());
	}
	while(sz(mp2)>(n/2)){
		mp2.erase(mp2.begin());
	}
	ll usedl=0,usedr=sz(s1)-1;
	REP(i,n){
		if(mp1.empty()){
			ans[usedl++]=*mp2.rbegin();
		}
		else if(mp2.empty()){
			ans[usedl++]=*mp1.begin();
		}
		else if((*mp1.begin())<(*mp2.rbegin())){
			if(i%2==0){
				ans[usedl++]=(*mp1.begin());
				mp1.erase(mp1.begin());
			}
			else{
				ans[usedl++]=(*mp2.rbegin());
				mp2.erase(--mp2.end());
			}
		}
		else{
			if(i%2==0){
				ans[usedr--]=(*mp1.rbegin());
				mp1.erase(--mp1.end());
			}
			else{
				ans[usedr--]=(*mp2.begin());
				mp2.erase(mp2.begin());
			}
		}
	}
	REP(i,n){
		cout<<ans[i];
	}
}