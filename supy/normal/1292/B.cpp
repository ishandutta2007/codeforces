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
const int N = 666666;
ll x[N],y[N],ax,ay,bx,by,res,n;
ll Abs(ll x){return x>0?x:-x;}
ll solve(int p, ll t){
	int res=0;ll sx=x[p],sy=y[p];
	per(i,p-1,0)if(t>=Abs(sx-x[i])+Abs(sy-y[i])){
		t-=Abs(sx-x[i])+Abs(sy-y[i]);res++;sx=x[i];sy=y[i];
	}
	else return res;
	rep(i,p+1,n)if(t>=Abs(sx-x[i])+Abs(sy-y[i])){
		t-=Abs(sx-x[i])+Abs(sy-y[i]);res++;sx=x[i];sy=y[i];
	}
	else return res;
	return res;
}
int main() {
	read(x[0]);read(y[0]);
	read(ax);read(ay);
	read(bx);read(by);
	ll xs,ys,t;read(xs);read(ys);read(t);
	while(x[n]<=2e16&&y[n]<=2e16){
		n++;
		x[n]=ax*x[n-1]+bx;y[n]=ay*y[n-1]+by;
	}
	rep(i,0,n)if(t>=Abs(xs-x[i])+Abs(ys-y[i])){
		umax(res,1+solve(i,t-(Abs(xs-x[i])+Abs(ys-y[i]))));
	}
	cout<<res;
	return 0;
}