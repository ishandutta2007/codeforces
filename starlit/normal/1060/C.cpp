#include<bits/stdc++.h>
#define N 2003
using namespace std;
int n,m,li,s,a[N],b[N],ma[N],mb[N],ans;
int main(){
	scanf("%d%d",&n,&m);
	memset(ma,0x3f,sizeof ma);
	memset(mb,0x3f,sizeof mb);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		s=0;
		for(int j=i;j;j--)
		s+=a[j],ma[i-j+1]=min(ma[i-j+1],s);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		s=0;
		for(int j=i;j;j--)
		s+=b[j],mb[i-j+1]=min(mb[i-j+1],s);
	}
	scanf("%d",&li);
	for(int i=1,j=m;i<=n&&j;i++){
		for(;1ll*ma[i]*mb[j]>li;j--);
		ans=max(ans,i*j);
	}
	printf("%d",ans);
}