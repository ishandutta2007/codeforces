#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm> 
#define N 100005
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;

int n,c,d,ans;
int p1[N],p2[N];
int newp1[N],newp2[N];
struct F {
	int b,p;
} x[N],y[N];
int l1,l2;
int cmp(F x, F y) {
	return x.p<y.p;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
//	freopen("1.in","r",stdin);
	read(n); read(c); read(d);
	rep(i,1,n) {
		int X,Y; char s[2]; read(X); read(Y); scanf("%s",s);
		if (s[0]=='C') {l1++; x[l1].b=X; x[l1].p=Y;}
		else {l2++; y[l2].b=X; y[l2].p=Y;}
	}
	if (l1) sort(x+1,x+l1+1,cmp);
	if (l2) sort(y+1,y+l2+1,cmp);
//	rep(i,1,l1) printf("%d %d\n",x[i].b,x[i].p);
//	puts("");
//	rep(i,1,l2) printf("%d %d\n",y[i].b,y[i].p);
	int l=1,size=x[l1].p;
	rep(i,1,c) {
		p1[i]=p1[i-1];
		while (l<=l1&&x[l].p==i) p1[i]=max(p1[i],x[l++].b);
	}
	l=1;size=y[l2].p;
	rep(i,1,d) {
		p2[i]=p2[i-1];
		while (l<=l2&&y[l].p==i) p2[i]=max(p2[i],y[l++].b);
	}
	rep(i,1,l1) newp1[i]=max(newp1[i-1],x[i].b);
	rep(i,1,l2) newp2[i]=max(newp2[i-1],y[i].b);
//	rep(i,1,c) printf("%d ",p1[i]); puts("");
//	rep(i,1,d) printf("%d ",p2[i]); puts("");
	//
	if (p1[c]>0&&p2[d]>0) ans=max(ans,p1[c]+p2[d]);
	for (int i=l1; i>=1; i--) {
		if (x[i].p>=c) continue;
		if (x[i].p+x[i].p<=c) {
			if (newp1[i-1]>0) ans=max(ans,x[i].b+newp1[i-1]);
		}
		else if (p1[c-x[i].p]>0) ans=max(ans,x[i].b+p1[c-x[i].p]);
	}
	for (int i=l2; i>=1; i--) {
		if (y[i].p>=d) continue;
		if (y[i].p+y[i].p<=d) {
			if (newp2[i-1]>0) ans=max(ans,y[i].b+newp2[i-1]);
		}
		else if (p2[d-y[i].p]>0) ans=max(ans,y[i].b+p2[d-y[i].p]);
	}	
	printf("%d",ans);
	return 0;
}