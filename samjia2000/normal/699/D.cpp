#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

const int N = 200010;

int fa[N],a[N],v[N];
int n,ans;
bool bz[N];
int u[N],k,w;

int getfather(int x){
	if (fa[x]==x)return x;
	return fa[x]=getfather(fa[x]);
}

int main(){
	scanf("%d",&n);
	fo(i,1,n)fa[i]=i;
	w=0;
	fo(i,1,n){
		scanf("%d",&a[i]);
		int f=getfather(a[i]);
		if (f!=i)fa[i]=f;
		else{
			if (a[i]==i&&!w)w=i;
			else u[++ans]=i;
		}
	}
	if (w){
		fo(i,1,ans)v[u[i]]=w;
		printf("%d\n",ans);
		fo(i,1,n)
		if (v[i])printf("%d ",v[i]);else printf("%d ",a[i]);
		putchar('\n');
	}
	else{
		fo(i,1,ans)v[u[i]]=u[1];
		printf("%d\n",ans);
		fo(i,1,n)
		if (v[i])printf("%d ",v[i]);else printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}