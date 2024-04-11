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

const int N = 1e5+11;
int n,a[N],qz[N],res=1e9,bit,gs[N];
map<int,Vi>Map;
bool ck(int l, int r){
//	if(l==1&&r==3)
//	printf("qwq %d %d %d\n",l,r,(l+1<r&&(gs[r]-gs[l]>1||gs[r]-gs[l]==1&&(~a[r]>>bit&1))));
	return (l+1<r&&(gs[r]-gs[l]>1||gs[r]-gs[l]==1&&(~a[r]>>bit&1)));
}
void doit(Vi f, Vi g){
	for(int i:g){
		int l=0,r=SZ(f)-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(ck(f[mid],i))umin(res,i-f[mid]-2),l=mid+1;else r=mid-1;
		}
	}
}
int main() {
	read(n);rep(i,1,n)read(a[i]),qz[i]=qz[i-1]^a[i];
	for(bit=0;bit<=30;bit++){
		rep(i,1,n)gs[i]=gs[i-1]+(a[i]>>bit&1);
		Map.clear();
		rep(i,0,n)Map[qz[i]>>bit+1].pb(i);
		for(auto it:Map){
			Vi b[2];
			for(auto i:it.se)b[qz[i]>>bit&1].pb(i);
			if(SZ(b[0])&&SZ(b[1]))doit(b[0],b[1]),doit(b[1],b[0]);
		}
	}
	cout<<(res<=n?res:-1);
	return 0;
}