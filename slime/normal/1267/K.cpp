#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int _;
ll k;

ll calc(VI d) {
	ll z=1;
	rep(i,2,SZ(d)+2) {
		int cnt=0;
		rep(j,0,SZ(d)) if (d[j]<i) cnt++;
		z=z*(cnt-i+2);
	}
	int f=0;
	rep(i,0,SZ(d)) {
		if (i==0||d[i]!=d[i-1]) f=1;
		else f++;
		z/=f;
	}
	return z;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld",&k);
		VI d;
		rep(i,2,101) {
			d.pb(k%i);
			k/=i;
			if (k==0) break;
		}
		sort(all(d));
		ll ans=calc(d);
		if (d[0]==0) {
			VI dd=d; dd.erase(dd.begin());
			ans-=calc(dd);
		}
		printf("%lld\n",ans-1);
	}
}