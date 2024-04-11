#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
int n;
char x[105],y[105];
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge() {
	rep(i,1,n) if (x[i]<y[i]) return 0;
	return 1;
}
int main()
{
	scanf("%s%s",x+1,y+1); n=strlen(x+1);
	if (!judge()) {puts("-1"); return 0;}
	rep(i,1,n) printf("%c",y[i]);
	return 0;
}