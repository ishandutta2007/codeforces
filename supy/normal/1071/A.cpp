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
const int N = 233;
int a,b;Vi x,y;bool used[101000];
bool ck(int n, int a, int b){
	memset(used,0,sizeof(used));x.clear();y.clear();
	per(i,n,1)if(a>=i)used[i]=1,x.pb(i),a-=i;
	per(i,n,1)if(!used[i])y.pb(i),b-=i;
	return a>=0&&b>=0;
}
int main() {
	read(a);read(b);
	int l=max((int)sqrt(2LL*(a+b))-5,0),r=l+10;
	per(i,r,l)if(ck(i,a,b)){
		printf("%d\n",SZ(x));rep(i,0,SZ(x)-1)printf("%d ",x[i]);puts("");
		printf("%d\n",SZ(y));rep(i,0,SZ(y)-1)printf("%d ",y[i]);puts("");
		return 0;
	}
	return 0;
}