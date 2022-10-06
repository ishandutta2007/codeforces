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
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;

int n,k,cnt;
int a[50],len;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(k);
	int tmp=n;
	if (n==0) {puts("0"); return 0;} //!!!!!!!!!!!!
	while (tmp) {cnt+=(tmp%10==0); tmp/=10; len++;}
	if (cnt<k) {printf("%d",len-1); return 0;}
	tmp=n; cnt=0; int num=0;
	while (tmp) {cnt+=(tmp%10==0); tmp/=10; num++; 
		if (cnt==k) {printf("%d",num-cnt); return 0;}}
}