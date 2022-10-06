#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lc(k) (k<<1)
#define rc(k) (k<<1|1)
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 533333;
int n,m,a[N],b[N],res,prime[N],size;
Vi t[N<<1];
inline int solve(int s, int p){
	s%=p;int res=0;rep(i,1,n)res+=a[i]%p==s;
	rep(i,1,m)res+=(1LL*b[i]+p/2)%p==s;
	return res;
}
inline int getmid(int p, int *a, int n){
	int x=-1,y=0;
	rep(i,1,n){
		int v=a[i]%p;if(x==v&&y)y++;else if(!y)y++,x=v;else y--;
	}
	return x;
}
/*inline bool ck(int p, int l, int r, int *a){
	int x=-1,y=0;
	rep(i,l,r){
		int v=a[i]%p;if(x==v&&y)y++;else if(!y)y++,x=v;else y--;
	}
	int cnt=0;rep(i,l,r)cnt+=a[i]%p==x;return cnt>=(r-l+1)/2+1;
}
inline void build1(int k, int l, int r, int *a){
	if(l==r){
		int v=a[r+1]-a[r];
		for(int i=1;prime[i]*prime[i]<=v;i++)if(v%prime[i]==0){
			t[k].pb(prime[i]);while(v%prime[i]==0)v/=prime[i];
		}
		if(v>1)t[k].pb(v);return;
	}	
	int mid=(l+r)>>1;build1(lc(k),l,mid);build1(rc(k),mid+1,r);
	per(i,SZ(t[lc(k)])-1,0)if(ck(t[lc(k)][i],l,r+1,a))t[k].pb(t[lc(k)][i]);
	per(i,SZ(t[rc(k)])-1,0)if(ck(t[rc(k)][i],l,r+1,a))t[k].pb(t[rc(k)][i]);
}*/
map<int,int>QAQ;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int main() {
	rep(i,2,100000)if(isprime(i))prime[++size]=i;
	int x;read(n);read(x);rep(i,1,n)read(a[i]),QAQ[a[i]]++;
	read(m);read(x);rep(i,1,m)read(b[i]),res=max(res,1+QAQ[b[i]]);
	res=max(res,solve(0,2));res=max(res,solve(1,2));
	rep(i,1,30){//1<<i
		res=max(res,solve(getmid(1<<i,a,n),1<<i));
		res=max(res,solve(getmid(1<<i,b,m)+(1<<(i-1)),1<<i));
	}
	/*build1(1,1,n-1,a);per(i,SZ(t[1])-1,0)res=max(res,solve(getmid(t[1][i],a),t[1][i]));
	rep(i,0,N-1)t[i].clear();
	build1(1,1,m-1,b);per(i,SZ(t[1])-1,0)res=max(res,solve(getmid(t[1][i],a),t[1][i]));*/
	printf("%d",res);
	return 0;
}