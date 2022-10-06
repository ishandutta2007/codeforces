#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define abs(a) ((a)>0 ? (a) : (-a))
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 1005
int n,a[N],b[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int judge() {
	rep(i,1,n) if (a[i]!=b[i]) return 1;
	rep(i,2,n) rep(j,1,i-1) if (a[i]>a[j]) return -1;
	return 0;
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]),read(b[i]);
	if (judge()==1) puts("rated");
	else if (judge()==0) puts("maybe");
	else puts("unrated");
	return 0;
}