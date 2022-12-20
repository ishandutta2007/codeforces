// new day,new strength,new thougts
#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define F first
#define S second
#define sz(c) int((c).size())
#define REP(i,n)  for(int i=0;i<int(n);i++)
#define REPD(i,n) for(int i=int(n)-1;i>=0;i--)
#define FOR(i,a,b) for(int i=int(a);i<=int(b);i++)
#define FORD(i,a,b) for(int i=int(a);i>=int(b);i--)
#define FORK(i,a,b,c) for(int i=int(a);i<=b;i+=c)
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=1010;
const ll mod=1e9+7;

ll S[maxn];

int main(){
    ll n,m,q;cin>>n>>m>>q;
    string s,t;cin>>s>>t;
    REP(i,(n-m+1)){
	bool np=0;
	REP(j,m){
	    if(s[i+j]!=t[j]){
		np=1;
		break;
	    }
	}
	S[i+1]=S[i]+(!np);
    }
    while(q--){
	ll l,r;cin>>l>>r;
	r=r-m+1;
	cout<<((r<l)?(0):(S[r]-S[l-1]))<<endl;
    }
}