#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 466666;
int n,p[N],pos[N],v1[N];
ll res;Pll v[N];
void modify1(int p){while(p<=n)v1[p]++,p+=p&-p;}
int qry1(int p){int r=0;while(p)r+=v1[p],p-=p&-p;return r;}
void add(Pll&a,Pll b){a=Pll(a.fi+b.fi,a.se+b.se);}
void mdy(int p, Pll x){while(p<=n)add(v[p],x),p+=p&-p;}
Pll qry(int p){Pll res(0,0);while(p)add(res,v[p]),p-=p&-p;return res;}
int main() {
	read(n);rep(i,1,n)read(p[i]),pos[p[i]]=i;
	rep(x,1,n){
		res+=x-1-qry1(pos[x]);modify1(pos[x]);
		ll cur=0;mdy(pos[x],Pll(1,pos[x]));
		int p=(x+1)/2,L=1,R=n;
		while(L<R){
			int mid=(L+R)>>1;
			if(qry(mid).fi<p)L=mid+1;else R=mid;
		}
	//	printf("%d:%d\n",p,L);
		//1..p
		cur+=1ll*p*(L-p)-(qry(L).se-1ll*p*(p+1)/2);
		//p+1..x
		cur+=-1ll*(x-p)*(L-p)+(qry(n).se-qry(L).se-(1ll*x*(x+1)/2-1ll*p*(p+1)/2));
		printf("%lld ",res+cur);
	}
	return 0;
}