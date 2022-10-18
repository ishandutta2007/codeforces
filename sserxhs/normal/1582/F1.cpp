#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
inline int Get_Int()
{
	char x=getchar();
	int num=0,bj=1;
	while(x<'0'||x>'9')
	{
		if(x=='-') bj=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9')
	{
		num=num*10+x-'0';
		x=getchar();
	}
	return num*bj;

 }
int m,n,i,j,k,a[100005];
int f[100005][555],s=0;
int Min[505];
int main()
{
	n=Get_Int();
	for(m=1;m<=500;m<<=1);
	for(i=1;i<=n;i++) a[i]=Get_Int();
	for(i=0;i<=m;i++) Min[i]=0x7fffffff;
	m--;
	Min[0]=0;
	f[0][0]=1;
	for(i=1;i<=n;i++)
	 {
	 	for(j=0;j<=m;j++) f[i][j]=f[i-1][j];
	    f[i][a[i]]=1;
		Min[a[i]]=min(Min[a[i]],a[i]);
	    for(k=0;k<=m;k++)
	     	if(Min[(k^a[i])]<a[i])
	     	 {
	     	 //	cout<<i<<" "<<k<<" "<<" "<<(k^a[i])<<" "<<Min[k^a[i]]<<endl;
			  f[i][k]=1;
			  Min[k]=min(Min[k],a[i]);
		     }
	 }
	 int ans=0;
	 for(i=0;i<=m;i++)if(f[n][i]) ans++;
	 printf("%d\n",ans);
	 for(i=0;i<=m;i++)
	  if(f[n][i]) printf("%d ",i);
	return 0;
}