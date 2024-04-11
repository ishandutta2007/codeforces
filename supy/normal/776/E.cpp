#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#include<cmath>
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
const int mo = 1e9 + 7;
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
ll n,k,ans;
inline ll phi(ll x) {
	ll res=x;
	rep(i,2,floor(sqrt(x)))
		if (x%i==0) {
			while (x%i==0) x/=i;
			res-=res/i;
		}
	if (x>1) res-=res/x;
	return res;
} 

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	scanf("%lld%lld",&n,&k);
	ll ans=n;
	rep(i,1,(k+1)/2) {
		ans=phi(ans);
		if (ans==1) break;
	}
	printf("%d",ans%mo);
	return 0;
}