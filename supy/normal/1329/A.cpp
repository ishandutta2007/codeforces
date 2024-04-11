#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 666666;
int n,m,l[N],a[N];ll tot,qz[N];
int main() {
	read(n);read(m);rep(i,1,m)read(l[i]),tot+=l[i];
	rep(i,1,m){a[i]=i;if(a[i]>n-l[i]+1){puts("-1");return 0;}}
	if(tot<n){puts("-1");return 0;}
	int L=0,r=m;
	while(L<=r){
		int mid=(L+r)/2;
		rep(i,1,mid)a[i]=i;
		ll sum=n;
		per(i,m,mid+1)sum-=l[i],a[i]=sum+1;
		if(sum<0){L=mid+1;}
		else{
			if(mid+1<=m&&a[mid+1]<=mid){L=mid+1;}
			else{
				memset(qz,0,sizeof(qz));
				rep(i,1,m)qz[a[i]]++,qz[a[i]+l[i]]--;
				rep(i,1,n)qz[i]+=qz[i-1];
				bool ok=1;
				rep(i,1,n)ok&=qz[i]>0;
				if(ok){rep(i,1,m)printf("%d ",a[i]);return 0;}
				r=mid-1;
			}
		}
	}
	return 0;
}