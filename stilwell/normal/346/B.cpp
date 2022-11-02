#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int la,lb,lc,i,j,k,x,y,z,xx,yy,zz,ans;
int fail[105],trans[105][35];
int f[105][105][105],froma[105][105][105],fromb[105][105][105],fromc[105][105][105];
char a[105],b[105],c[105],d[105];

int main()
{
	scanf("%s",a+1);la=strlen(a+1);
	scanf("%s",b+1);lb=strlen(b+1);
	scanf("%s",c+1);lc=strlen(c+1);
	for(i=1;i<=la;++i)a[i]-='A';a[++la]=30;
	for(i=1;i<=lb;++i)b[i]-='A';b[++lb]=31;
	for(i=1;i<=lc;++i)c[i]-='A';
	for(i=2;i<=lc;++i)
	{
		for(j=fail[i-1];j;j=fail[j])if(c[j+1]==c[i])break;
		if(c[j+1]==c[i])fail[i]=j+1;
	}
	for(i=0;i<lc;++i)
	for(j=0;j<26;++j)
	{
		for(k=i;k;k=fail[k])if(c[k+1]==j)break;
		if(c[k+1]==j)trans[i][j]=k+1;
	}
	for(i=1;i<=la;++i)
	for(j=1;j<=lb;++j)
	for(k=0;k<lc;++k)
	{
		if(f[i][j][k]>f[x][y][z])x=i,y=j,z=k;
		if(f[i+1][j][k]<f[i][j][k])
		{
			froma[i+1][j][k]=i;
			fromb[i+1][j][k]=j;
			fromc[i+1][j][k]=k;
			f[i+1][j][k]=f[i][j][k];
		}
		if(f[i][j+1][k]<f[i][j][k])
		{
			froma[i][j+1][k]=i;
			fromb[i][j+1][k]=j;
			fromc[i][j+1][k]=k;
			f[i][j+1][k]=f[i][j][k];
		}
		if(a[i]==b[j]&&f[i+1][j+1][trans[k][a[i]]]<f[i][j][k]+1)
		{
			froma[i+1][j+1][trans[k][a[i]]]=i;
			fromb[i+1][j+1][trans[k][a[i]]]=j;
			fromc[i+1][j+1][trans[k][a[i]]]=k;
			f[i+1][j+1][trans[k][a[i]]]=f[i][j][k]+1;
		}
	}
	ans=f[x][y][z];
	if(!ans)printf("0\n");
	else
	{
		while(ans)
		{
			xx=froma[x][y][z];
			yy=fromb[x][y][z];
			zz=fromc[x][y][z];
			if(xx==x-1&&yy==y-1)d[ans--]=a[xx]+'A';
			x=xx;y=yy;z=zz;
		}
		printf("%s\n",d+1);
	}
}