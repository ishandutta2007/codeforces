#include <bits/stdc++.h>
using namespace std;
const int N=505;
int f[N][N][N],nxt[N];
int n,m,q,i,j,k,x;
char s[N],t[N];
void getmn(int &x,int y){if (x>y) x=y;}
void get_next(char *s,int *nxt)
{
	int n,i,j;
	n=strlen(s+1);j=0;
	nxt[1]=0;
	for (i=2;i<=n;i++)
	{
		while (j&&s[i]!=s[j+1]) j=nxt[j];
		j+=s[i]==s[j+1];
		nxt[i]=j;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>s+1>>t+1;
	get_next(t,nxt);
	memset(f,0x3f,sizeof f);int inf=f[0][0][0];
	f[0][0][0]=0;
	for (i=0;i<n;i++) for (j=0;j<n;j++) for (k=0;k<m;k++) if (f[i][j][k]!=inf)
	{
		if (s[i+1]==t[k+1])
		{
			if (k==m-1) getmn(f[i+1][j+1][nxt[m]],f[i][j][k]);
			else getmn(f[i+1][j][k+1],f[i][j][k]);
			x=nxt[k];
			while (x&&(s[i+1]^1)!=t[x+1]) x=nxt[x];
			getmn(f[i+1][j][x+((s[i+1]^1)==t[x+1])],f[i][j][k]+1);
		}
		else
		{
			if (k==m-1) getmn(f[i+1][j+1][nxt[m]],f[i][j][k]+1);
			else getmn(f[i+1][j][k+1],f[i][j][k]+1);
			x=nxt[k];
			while (x&&s[i+1]!=t[x+1]) x=nxt[x];
			getmn(f[i+1][j][x+(s[i+1]==t[x+1])],f[i][j][k]);
		}
	}
	for (i=0;i<=n-m+1;i++)
	{
		x=*min_element(f[n][i],f[n][i]+m);
		cout<<(x==inf?-1:x)<<' ';
	}
}