#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
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

int ans=1,n,s[100006];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);
	rep(i,2,n+1) {
		int tmp=i; s[i]=1;
		rep(j,2,floor(sqrt(tmp)))
			if (tmp%j==0) {s[i]=2;ans=2; break;}
	}
	printf("%d\n",ans);
	rep(i,2,n+1) printf("%d ",s[i]);
	return 0;
}