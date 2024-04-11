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
typedef pair<int,int> Pii;
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
int f[27];
int solve(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0)return i;
	return n;
}
int main() {
	rep(i,0,25)f[i]=((1<<i+1)-1)/solve((1<<i+1)-1);
	int q;read(q);
	while(q--){
		int a;read(a);
		int mx=0;
		rep(i,0,26)if(a>>i&1)mx=i;
		if(a==(1<<mx+1)-1)printf("%d\n",f[mx]);
		else printf("%d\n",(1<<mx+1)-1);
	}
	return 0;
}