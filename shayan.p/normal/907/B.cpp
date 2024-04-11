// Believe in yourself...
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

int main(){
	string s[12];
	REP(i,11){
		getline(cin,s[i]);
	}
	ll a,b;cin>>a>>b;
	ll x=a%3,y=b%3;
	x=((x==0)?3:x);
	y=((y==0)?3:y);
	x=(x-1)*4+1;
	y=(y-1)*4+1;
	bool emp=0;
	REP(i,3){
		REP(j,3){
			if(s[x+i-1][y+j-1]=='.'){
				emp=1;
				s[x+i-1][y+j-1]='!';
			}
		}
	}
	if(!emp){
		REP(i,11){
			REP(j,sz(s[i])){
				if(s[i][j]=='.'){
					s[i][j]='!';
				}
			}
		}
	}
	REP(i,11){
		cout<<s[i]<<endl;
	}
}