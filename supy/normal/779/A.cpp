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
#define abs(a) ((a)>0 ? (a) : (-(a))) //attention
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;

int n,cnt1[7],cnt2[7];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n);
	rep(i,1,n) {int x; read(x); cnt1[x]++;}
	rep(i,1,n) {int x; read(x); cnt2[x]++;}
	rep(i,1,5) if ((cnt1[i]+cnt2[i])%2==1) { //careful
	//	printf("%d %d %d\n",i,cnt1[i],cnt2[i]); careful
		puts("-1"); return 0;
	}
	int ans=0;
	rep(i,1,5) ans+=abs(cnt1[i]-cnt2[i])/2;
	printf("%d",ans/2);
	return 0;
}