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
#define N 200005
char a[N],b[N];
int p[N],n,m,ans;
bool remv[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool judge(int k) {
	memset(remv,0,sizeof(remv));
	rep(i,1,k) remv[p[i]]=1;
	int l=0;
	rep(i,1,n) if (l<m&&!remv[i]&&a[i]==b[l+1]) l++;
	return l==m;
}
int main() {
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1); m=strlen(b+1);
	rep(i,1,n) read(p[i]);
	int l=0,r=n;
	while (l<=r) {
		int mid=(l+r)/2;
		if (judge(mid)) {ans=mid; l=mid+1;}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}