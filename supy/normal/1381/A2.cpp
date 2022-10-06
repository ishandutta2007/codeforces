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

const int N = 3e5+11;
int n;char s[N],t[N];
int ans[N],sz;
int main() {
//	cerr<<(int)'0'<<' '<<(int)'1'<<endl;
	int T;read(T);while(T--){
		read(n);sz=0;
		scanf("%s%s",s+1,t+1);
		int l=1,r=n;bool rev=0;
		per(i,n,1){
			if(t[i]==(s[r]^rev)){
				if(r>l)r--;else r++;
				continue;
			}
			if(t[i]==(s[l]^rev)){
				ans[++sz]=1;s[l]^=1;
			}
			if(t[i]==(s[l]^rev^1)){
				ans[++sz]=i;
				int tt=l<r?l+1:l-1;
				l=r;r=tt;rev^=1;
				continue;
			}
			assert(0);
		}
		printf("%d ",sz);rep(i,1,sz)printf("%d ",ans[i]);puts("");
	}
	return 0;
}