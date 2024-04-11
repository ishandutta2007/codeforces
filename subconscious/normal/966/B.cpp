#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define y1 FFF
using namespace std;
const int N=300005;
int c[N],q[N],x1,x2,n;
int a[N],b[N];
bool cmp(int x,int y){return c[x]<c[y];}
int main(){
	scanf("%d%d%d",&n,&x1,&x2);
	rep(i,n)scanf("%d",c+i),q[i]=i;
	sort(q+1,q+n+1,cmp);
	sort(c+1,c+n+1);
	rep(i,n)a[i]=(x1-1)/c[i]+1;
	rep(i,n)b[i]=(x2-1)/c[i]+1;
	rep(i,n)if(i+a[i]<=n&&i+a[i]+b[i+a[i]]-1<=n){
		puts("Yes");
		printf("%d ",a[i]);
		printf("%d ",b[i+a[i]]);
		for(int j=i;j<i+a[i];++j)printf("%d%c",q[j],j==i+a[i]-1?'\n':' ');
		for(int j=i+a[i];j<i+a[i]+b[i+a[i]];++j)printf("%d%c",q[j],j==i+a[i]+b[i+a[i]]-1?'\n':' ');
		//system("pause");
		return 0;
	}
	rep(i,n)if(i+b[i]<=n&&i+b[i]+a[i+b[i]]-1<=n){
		puts("Yes");
		printf("%d ",a[i+b[i]]);
		printf("%d ",b[i]);
		for(int j=i+b[i];j<i+b[i]+a[i+b[i]];++j)printf("%d%c",q[j],j==i+b[i]+a[i+b[i]]-1?'\n':' ');
		for(int j=i;j<i+b[i];++j)printf("%d%c",q[j],j==i+b[i]-1?'\n':' ');
		//system("pause");
		return 0;
	}
	puts("No");
	//system("pause");
	return 0;
}