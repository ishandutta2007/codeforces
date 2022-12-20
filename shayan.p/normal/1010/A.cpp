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
const ll Big=1e9+10;
const ld eps=0.000000000001;

ll a[maxn],b[maxn],n,m;

bool check(ld w){
    REP(i,n){
	w=w-(ld(w+m)/ld(a[i]));
	if(w<=eps)return 0;
	w=w-(ld(w+m)/ld(b[(i+1)%n]));
	if(w<=eps)return 0;
    }
    return 1;
}

int main(){
    cin>>n>>m;
    REP(i,n){
	cin>>a[i];
    }
    REP(i,n){
	cin>>b[i];
    }
    ld l=0,r=Big,ans=-1;
    REP(i,1000){
	ld mid=(l+r)/2;
	if(check(mid)){
	    ans=mid;
	    r=mid;
	}
	else{
	    l=mid;
	}
    }
    if(ans==ld(-1))
	cout<<-1;
    else
	cout<<setprecision(10)<<fixed<<ans;
}