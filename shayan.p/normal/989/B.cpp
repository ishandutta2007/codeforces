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
const ll maxn=2e5+10;
const ll mod=1e9+7;

#pragma GCC Optimize("Ofast")

int main(){
	ll n,p;cin>>n>>p;
	string s;cin>>s;
	bool did=0;
	FOR(i,p,n-1){
		did|=((s[i-p]=='0'&&s[i]=='1')||(s[i-p]=='1'&&s[i]=='0'));
		if(s[i-p]=='.'&&s[i]=='.'){
			s[i-p]='0';
			s[i]='1';
			did=1;
		}
		if(s[i-p]=='.'&&s[i]!='.'){
			s[i-p]=1-s[i]+'0'+'0';
			did=1;
		}
		if(s[i-p]!='.'&&s[i]=='.'){
			s[i]=1-s[i-p]+'0'+'0';
			did=1;
		}
	}
	if(did){
		REP(i,n)
			cout<<(s[i]=='1');
	}
	else{
		cout<<"No";
	}
}