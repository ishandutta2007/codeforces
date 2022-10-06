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
const int N = 2333;
int n,m,a[N],b[N],res,x;
int pa[N],pb[N],qz[N];
void init(int *a, int n, int *p){
	rep(i,1,n)qz[i]=qz[i-1]+a[i];
	rep(i,1,n){
		p[i]=1e9;
		rep(j,1,n-i+1)p[i]=min(p[i],qz[j+i-1]-qz[j-1]);
	}
}
int main() {
	read(n);read(m);rep(i,1,n)read(a[i]);rep(i,1,m)read(b[i]);read(x);
	init(a,n,pa);init(b,m,pb);
	rep(i,1,n)rep(j,1,m)if(1LL*pa[i]*pb[j]<=x)res=max(res,i*j);
	cout<<res;return 0;
}