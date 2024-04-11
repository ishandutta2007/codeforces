#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 200005
using namespace std;
int a[N],b[N],c[N],ans[N],n;
int cmp(int x,int y){return b[x]<b[y];}
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);
	rep(i,n)scanf("%d",b+i),c[i]=i;
	sort(a+1,a+n+1);
	sort(c+1,c+n+1,cmp);
	rep(i,n)ans[c[i]]=a[n-i+1];
	rep(i,n)printf("%d%c",ans[i],i==n?'\n':' ');
	return 0;
}