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
ll a[N],len;int n;
ll f(ll x){
	return n/x+1LL*n*(n/x-1)/2;
}
int main() {
	read(n);for(int i=1;i*i<=n;i++)if(n%i==0)a[++len]=f(i),a[++len]=f(n/i);
	sort(a+1,a+len+1);len=unique(a+1,a+len+1)-a-1;
	rep(i,1,len)printf("%lld ",a[i]);
	return 0;
}