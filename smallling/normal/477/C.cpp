#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int f[2020][2020];
int now,len1,len2,nowx,ans;
char s[2020],p[2020];

int Delete(int x)
{
	ans=0;
	if(x<len2)return -1;
	nowx=x;x=len2;
	while(nowx&&x)
	{
		if(s[nowx]==p[x])x--,nowx--;
		else nowx--,ans++;
	}
	if(!x)return ans;
	return -1;
}

int main()
{
	scanf("%s",s+1);
	scanf("%s",p+1);
	len1=strlen(s+1);
	len2=strlen(p+1);
	for(int i=0;i<=len1;i++)
		for(int j=0;j<=len1;j++)
			if(i<j)f[i][j]=-0x3f3f3f3f;
	for(int i=1;i<=len1;i++)
	{
		now=Delete(i);
		for(int j=0;j<=len1;j++)f[i][j]=max(f[i][j],f[i-1][j]);
		if(now==-1)continue;
		for(int j=0;j<=len1;j++)
			if(now<=j)f[i][j]=max(f[i-len2-now][j-now]+1,f[i][j]);
	}
	for(int i=0;i<=len1;i++)printf("%d ",f[len1][i]);
}