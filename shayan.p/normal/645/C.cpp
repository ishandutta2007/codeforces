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
#define all(s) (s).begin(),(s).end()
#define bit(num,i) ((num>>i)&1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

const ll inf=4e18;
const ll maxn=2e5+10;
const ll mod=1e9+7;

ll bk[maxn],fr[maxn];

int main(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    
    ll lst=-1;
    REP(i,sz(s)){
	if(s[i]=='0')
	    lst=i;
	bk[i]=lst;
    }
    lst=n;
    REPD(i,sz(s)){
	if(s[i]=='0')
	    lst=i;
	fr[i]=lst;
    }
    
    k++;
    ll r=0,sm=0,ans=inf;
    REP(l,n){
	while(r<n&&sm<k){
	    sm+=(s[r++]=='0');
	}
	if(sm<k){
	    break;
	}
	if(s[l]=='0'){
	    ll md=(l+r-1)/2;
	    ans=min(ans,min(max(r-1-bk[md],bk[md]-l),max(r-1-fr[md],fr[md]-l)));
	}
	sm-=(s[l]=='0');
    }
    cout<<ans;
}