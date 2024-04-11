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
const ll maxn=1e6+10;
const ll mod=1e9+7;

ll a[maxn],b[maxn],sm[maxn][3],ans=inf;

int main(){
    ll n;cin>>n;
    FOR(i,1,n){
	cin>>a[i];
    }
    sort(a+1,a+n+1);
    FOR(i,1,n){
	sm[i][0]=sm[i-1][0]+a[i];
	sm[i][1]=sm[i-1][1]+abs(a[i]-3);
	sm[i][2]=sm[i-1][2]+abs(a[i]-4);
    }
    FOR(x,0,n){
	ll y=sm[n][0]-3*x;
	if(y<0 || y>x)continue;
	ll A=n-x,B=x-y,C=y;
	ans=min(ans,sm[A][0]+sm[A+B][1]-sm[A][1]+sm[A+B+C][2]-sm[A+B][2]);
    }
    cout<<((ans==inf)?(-1):(ans/2));
}