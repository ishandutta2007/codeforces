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
const ll maxn=2e5+10;
const ll mod=1e9+7;

int main(){
    ll n,m;cin>>n>>m;
    string a,b;cin>>a>>b;
    bool is=0;
    REP(i,n){
	if(a[i]=='*')
	    is=1;
    }
    if(is){
	if((n-1)>m){
	    cout<<"NO";
	    return 0;
	}
	bool is=0;
	REP(i,sz(a)){
	    if(a[i]=='*'){
		is=1;
		break;
	    }
	    if(a[i]!=b[i]){
		cout<<"NO";
		return 0;
	    }
	}
	if(!is){
	    if(sz(a)==sz(b)){
		cout<<"YES";
	    }
	    else{
		cout<<"NO";
	    }
	    return 0;
	}
	reverse(all(a));
	reverse(all(b));
	REP(i,sz(a)){
	    if(a[i]=='*')
		break;
	    if(a[i]!=b[i]){
		cout<<"NO";
		return 0;
	    }
	}
	cout<<"YES";
    }
    else{
	cout<<((a==b)?"YES":"NO");
    }
}