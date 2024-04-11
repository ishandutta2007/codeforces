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
const ll maxn=3e5+10;
const ll mod=1e9+7;

ll a[maxn],b[maxn],sm[2][maxn],ss[maxn];

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    FOR(i,1,n){
	cin>>b[i];
    }
    FORD(i,n,1){
	ss[i]=ss[i+1]+a[i]+b[i];
	sm[0][i]=sm[0][i+1]+ss[i+1]+b[i]*(2*(n-i+1)-1);
	sm[1][i]=sm[1][i+1]+ss[i+1]+a[i]*(2*(n-i+1)-1);
    }
    ll ans=0,num=0;
    FOR(i,1,n){
	ll bf=2*i-2;
	if(i%2)
	    ans=max(ans,num+bf*ss[i]+sm[0][i]);
	else
	    ans=max(ans,num+bf*ss[i]+sm[1][i]);
	if(i%2)
	    num+=bf*a[i]+(bf+1)*b[i];
	else
	    num+=bf*b[i]+(bf+1)*a[i];
    }
    cout<<ans;
}