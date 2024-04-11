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
int ans;
char s[500];
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int main()
{
	int n; 
	read(n);
	rep(i,1,n) {
		scanf("%s",s);
		if (s[0]=='T') ans+=4;
		if (s[0]=='C') ans+=6;
		if (s[0]=='O') ans+=8;
		if (s[0]=='D') ans+=12;
		if (s[0]=='I') ans+=20;
	}
	printf("%d\n",ans);
	return 0;
}