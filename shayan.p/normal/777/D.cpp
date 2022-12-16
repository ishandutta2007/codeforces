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

const ll inf=4e18;
const ll maxn=5e5+10;

#pragma GCC Optimize("Ofast")

string s[maxn];
ll leng[maxn];

ll f(ll l,ll r,ll h){
	ll lst=-10;
	FORD(i,r,l){
		ll val=(leng[i]<=h?-1:s[i][h]-'a');
		if(lst==-10)
			lst=val;
		if(val>lst){
			FOR(j,l,i)
				leng[j]=h;
			break;
		}
		lst=min(lst,val);
	}
	
	ll st=(leng[l]<=h?-1:s[l][h]-'a'),beg=l;
	FOR(i,l,r){
		ll val=(leng[i]<=h?-1:s[i][h]-'a');
		if(st!=val){
			if(st!=-1)
				f(beg,i-1,h+1);
			st=val;
			beg=i;
		}
	}
	if(st!=-1)
		f(beg,r,h+1);
}

int main(){
	ll n;cin>>n;
	REP(i,n){
		cin>>s[i];
		leng[i]=sz(s[i]);
	}
	f(0,n-1,1);
	REP(i,n){
		REP(j,leng[i])
			cout<<s[i][j];
		cout<<endl;
	}
}