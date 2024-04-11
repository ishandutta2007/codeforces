#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
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
const int N = 666666;
int n,h,x[N],y[N],qz[N],res;
int main() {
	read(n);read(h);rep(i,1,n)read(x[i]),read(y[i]),qz[i]=qz[i-1]+y[i]-x[i];
	int t=1;
	rep(s,1,n){
		while(t+1<=n&&y[t+1]-x[s]-(qz[t+1]-qz[s-1])<h)t++;
		res=max(res,h+qz[t]-qz[s-1]);
	}
	printf("%d",res);
	return 0;
}