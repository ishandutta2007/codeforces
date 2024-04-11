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
#define N 2000005 //careful!
int n,m,num;
int x[N],s[N],l;
struct Y {
	int v,p;
} y[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bool cmp(Y a, Y b) {return a.v<b.v;}
void merge(int p2) {
	int p1=1,size=n+m-p2+1; l=1;
	while (l<=size) {
		if (p1>n) {s[l++]=y[p2].v; p2++;}
		else if (p2>m) {s[l++]=x[p1]; p1++;}
		else {
			if (x[p1]<y[p2].v) {s[l++]=x[p1]; p1++;}
			else {s[l++]=y[p2].v; p2++;}
		}
	}
}
bool judge(int k) {
	merge(m-k+1); l--; int lst=(l-1)/num+1,now=1; //careful!!!  l chongming
//	printf("%d %d:",k,lst); rep(i,1,l) printf("%d ",s[i]); puts("");
	rep(i,0,lst-1) {
		int cnt=1;
		while (cnt<=num&&now<=l) { //chongming
		//	printf("%d %d\n",s[now],i);
			if (s[now]<i) return 0; now++; cnt++; //cnt!!
		}
	}
	return 1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);read(m);read(num);
	rep(i,1,n) read(x[i]);
	rep(i,1,m) {read(y[i].v); y[i].p=i;}
	sort(x+1,x+n+1);
	sort(y+1,y+m+1,cmp);
	int ans=-1,l=0,r=m;
	while (l<=r) {
		int mid=(l+r)>>1;
		if (judge(mid)) {ans=mid; l=mid+1;}
		else r=mid-1;
	}
	if (ans==-1) puts("-1");
	else {
		printf("%d\n",ans);
		rep(i,1,ans) printf("%d ",y[m-i+1].p);
	}
	return 0;
}