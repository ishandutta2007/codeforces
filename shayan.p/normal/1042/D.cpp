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
const ll maxn=4e5+10;
const ll mod=1e9+7;

ll a[maxn],f[maxn],arr[maxn],C;
int sm[maxn];

void add(int ind){
    while(ind<maxn){
	sm[ind]++;
	ind+=(ind & -ind);
    }
}
ll ask(int ind){
    ll ans=0;
    while(ind>0){
	ans+=sm[ind];
	ind-=(ind & -ind);
    }
    return ans;
}

int main(){
    ll n,t;scanf("%lld%lld",&n,&t);
    FOR(i,1,n){
	ll x;scanf("%lld",&x);
	a[i]=a[i-1]+x;
	f[i]=a[i]-t;
	arr[C++]=a[i];
	arr[C++]=a[i]-t;
    }
    arr[C++]=0;
    sort(arr,arr+C);
    C=unique(arr,arr+C)-arr;
    FOR(i,1,n){
	a[i]=lower_bound(arr,arr+C,a[i])-arr+1;
	f[i]=lower_bound(arr,arr+C,f[i])-arr+1;
    }
    
    int zr=lower_bound(arr,arr+C,0)-arr+1;
    add(zr);
    
    ll ans=0;
    FOR(i,1,n){
	ans+=ask(maxn-1)-ask(f[i]);
	add(a[i]);
    }
    printf("%lld\n",ans);
}