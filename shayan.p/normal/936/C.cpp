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
const ll mod=1e9+7;
const ll maxn=2e5+10;

ll n;
string s,t;
vector<ll>ans;

void f(ll x){
	string cop=s;
	REPD(i,x){
		s[i]=cop[n-1-i];
	}
	REP(i,n-x)
		s[i+x]=cop[i];
}

ll Find(char ch,ll st){
	FOR(i,st,n-1)
		if(s[i]==ch)
			return n-i;
	return -1;
}

int main(){
	cin>>n;
	cin>>s>>t;
	ll midl,midr,st;
	if(n%2){
		ll num=Find(t[n/2],0);
		ans.PB(num);
		if(n-num!=0)
			ans.PB(n-num);
		ans.PB(1);
		f(num);
		f(n-num);
		f(1);
		midl=(n/2)-1;midr=(n/2)+1;
		st=1;
	}
	else{
		midl=(n/2)-1;midr=(n/2);
		st=0;
	}
	
	ll state=0;
	FOR(i,st,n-1){
		ll pos=Find((state?t[midr]:t[midl]),i);
		if(pos==-1){
			cout<<-1;
			return 0;
		}
		
		ans.PB(pos);
		if(n-pos-i!=0)
			ans.PB(n-pos-i);
		ans.PB(i+1);
		f(pos);
		f(n-pos-i);
		f(i+1);
		
		if(state)
			midr++;
		else
			midl--;
		state=1-state;
	}
	if(s!=t){
		ans.PB(n);
		f(n);
	}
	cout<<sz(ans)<<endl;
	REP(i,sz(ans))
		cout<<ans[i]<<" ";
}