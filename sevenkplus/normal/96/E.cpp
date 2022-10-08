#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define P 1000000007
int f[1002][1002],m,a[1020],h[1020][2];char s[1020];
int gg(int p,int l,int b)
{
	if(p==-1)return 0;
	if(!b&&f[p][l]!=-1)return f[p][l];
	int r=0;
	for(int i=0,e=b?a[p]:9;i<=e;i++)
		if(i==4||i==7)
			if(l==m)r+=gg(p-1,0,b&&i==e),r%=P;
			else r+=h[p][b&&i==e],r%=P;
		else r+=gg(p-1,l==m?m:(l+1),b&&i==e),r%=P;
	return b?r:(f[p][l]=r);
}
int ff(char *s)
{
	int n=strlen(s);
	for(int i=n-1;i>=0;i--)a[i]=s[i]-'0';
	memset(h,-1,sizeof h);
	h[0][0]=h[0][1]=1;
	for(int i=1;i<=n;i++)h[i][0]=(long long)h[i-1][0]*10%P;
	for(int i=1;i<=n;i++)h[i][1]=((long long)h[i-1][1]+(long long)a[i-1]*h[i-1][0])%P;
	return gg(n-1,m,1);
}
int main()
{
	memset(f,-1,sizeof f);
	int _;scanf("%d%d",&_,&m);
	while(_--)
	{
		scanf("%s",s);int n=strlen(s),SA;
		reverse(s,s+n);
		if(n==1&&s[0]=='1')SA=0;else
		{
			int i=0;
			while(s[i]=='0')s[i]='9',i++;
			s[i]--;
			if(i==n-1&&s[i]=='0')n--;
			SA=ff(s);
		}
		scanf("%s",s);n=strlen(s);
		reverse(s,s+n);
		int SB=ff(s);
		SB-=SA;while(SB<0)SB+=P;
		printf("%d\n",SB);
	}
	return 0;
}