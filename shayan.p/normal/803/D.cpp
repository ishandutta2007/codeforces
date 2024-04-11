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
const ll mod=1e9+7;
const ll maxans=1e6+10;

vector<ll>block;
ll k;

bool pos(ll num){
	ll round=0,last;
	REP(i,sz(block)){
		if(block[i]>num)return 0;
		round++;
		ll sum=0;
		while(i<sz(block)&&sum+block[i]<=num){
			sum+=block[i];
			i++;
		}
		i--;
	}
	return (round<=k);
}
int main(){
	cin>>k;
	string s;
	getline(cin,s);
	getline(cin,s);
	ll num=0;
	REP(i,sz(s)){
		num++;
		if(s[i]==' '||s[i]=='-'){
			block.PB(num);
			num=0;
		}
	}
	block.PB(num);	
	ll l=0,r=maxans,ans=-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(pos(mid)){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	cout<<ans;
}