#include <stdio.h>
#include <map>
#include <algorithm>

int n,k,e,x,i;

std::map <int, int> m,mm;
long long p[2000000],h[2000000];
int kk,a[2000000],b[2000000],yy[2000000],pp[2000000],w;

typedef struct{int d,l;} T;

T q[2000000];

bool my(T A,T B){
	return A.d<B.d||A.d==B.d&&A.l<B.l;
}

bool rr(int x,int y,int l){
	long long h1=(h[y+l-1]-h[y-1]+1000000007)%1000000007;
	long long h2=(h[x+l-1]-h[x-1]+1000000007)*p[y-x]%1000000007;
	return h1==h2;
}

int main(){
//	freopen("1.in","r",stdin);
	scanf("%d",&n);
	for (i=1;i<=n;i++)scanf("%d",&a[i]);
	for (i=1;i<=n;i++)if (!mm[a[i]]){
		b[i]=++e;
		mm[a[i]]=e;
	}else b[i]=mm[a[i]];
	p[0]=1;
	for (i=1;i<=n;i++)p[i]=(p[i-1]*1000003)%1000000007;
	h[0]=0;
	for (i=1;i<=n;i++)h[i]=(h[i-1]+p[i-1]*b[i])%1000000007;
	for (i=n;i>0;i--){
		w=m[a[i]];
		for (;w;w=pp[w])if (rr(i,yy[w],yy[w]-i)){
			q[++k].d=yy[w]-i;
			q[k].l=i;
		}
		yy[++kk]=i;
		pp[kk]=m[a[i]];
		m[a[i]]=kk;
	}
	std::sort(q+1,q+k+1,&my);
	int u=1;
	for (i=1;i<=k;i++)if (q[i].l>=u)u=q[i].l+q[i].d;
	printf("%d\n",n-u+1);
	for (i=u;i<n;i++)printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}