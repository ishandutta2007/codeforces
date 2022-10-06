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

const int N = 4e5+11;
int n,sta[N],top,ans[N];
int zhi[N<<2],val[N<<2];
void upd(int k){val[k]=min(val[k<<1],val[k<<1|1]);}
void push(int k, int x){
	zhi[k]=x;val[k]=x;
}
void pushdown(int k){
	if(zhi[k]){
		push(k<<1,zhi[k]);push(k<<1|1,zhi[k]);
		zhi[k]=0;
	}
}
int qry(int k, int x, int l, int r){//<=x
	if(l==r){if(val[k]<=x)return l;return n+1;}
	pushdown(k);int mid=(l+r)>>1;
	if(val[k<<1]<=x)return qry(k<<1,x,l,mid);
	return qry(k<<1|1,x,mid+1,r);
}
void mdy(int k, int l, int r, int x, int L, int R){
	if(l==L&&r==R){push(k,x);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)mdy(k<<1,l,r,x,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,x,mid+1,R);
	else mdy(k<<1,l,mid,x,L,mid),mdy(k<<1|1,mid+1,r,x,mid+1,R);
	upd(k);
}
void GG(){puts("NO");exit(0);}
int main() {
	read(n);
	int gs=0;
	rep(i,1,n*2){
		char t[5];scanf("%s",t);
		if(t[0]=='+')sta[++top]=++gs,mdy(1,top,top,1,1,n);
		else if(top==0)GG();
		else{
			int x;read(x);
			int p=qry(1,x,1,n);
			if(p>top)GG();
			mdy(1,p,top,x,1,n);
			ans[sta[top--]]=x;
		}
	}
	puts("YES");rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}