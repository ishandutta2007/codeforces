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
typedef long double ld;
int k,q;
const ld EPS = 1e-7;
ld f[2][1005];
ld Day[1000005];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(k); read(q);
	int cnt=0;
	f[0][0]=1;
	while (1) {
		cnt++; int p=cnt&1,q=p^1;
		memset(f[p],0,sizeof(f[p]));
		rep(i,1,k) f[p][i]=f[q][i]*i/k+f[q][i-1]*(k-i+1)/k;
		Day[cnt]=f[p][k];
		if (Day[cnt]>=0.5-EPS) {//printf("%d\n",cnt); 
		break;}
	}
	rep(i,1,q) {
		int x; read(x); ld y=(x-EPS)/2000.0;
		rep(j,1,cnt) if (Day[j]>=y) {printf("%d\n",j); break;}
	//	printf("%d\n",lower_bound(Day+1,Day+cnt+1,));
	}
	return 0;
}