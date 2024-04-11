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
int a,b;
inline void read(int &x) {
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge() {
	for (int i=1; ; i++) {
		bool x=i&1;
		if (x==1) {a-=i; if (a<0) return 1;}
		else {b-=i; if (b<0) return 0;}
	}
}
int main()
{
	read(a); read(b);
	if (!judge()) puts("Valera");
	else puts("Vladik");
	return 0;
}