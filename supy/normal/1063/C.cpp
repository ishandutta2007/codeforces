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
const int N = 55;
int l=1,r=1e9,a,b;
int query(int x, int y){
	printf("%d %d\n",x,y);fflush(stdout);
	char s[19];scanf("%s",s);return s[0]=='b';
}
int main() {
	int n;read(n);a=query(l,1);b=a^1;
	rep(i,2,n){
		int mid=(l+r)>>1;int v=query(mid,1);
		if(v==a)l=mid;else r=mid;
	}
	printf("%d %d %d %d",l,0,r,2);fflush(stdout);
	return 0;
}