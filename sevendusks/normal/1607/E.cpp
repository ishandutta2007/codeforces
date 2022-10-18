/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100;
int T,n,m,k;
char s[N];
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
signed main()
{
	T=read();
	while (T--)
	{
		n=read();m=read();
		scanf("%s",s+1);
		int dx[2],dy[2],x=0,y=0;
		dx[0]=dx[1]=dy[0]=dy[1]=0;
		k=strlen(s+1);bool bl=1;
		for (int i=1;i<=k;i++)
		{
			if (s[i]=='L') y--;
			if (s[i]=='R') y++;
			if (s[i]=='U') x--;
			if (s[i]=='D') x++;
			dx[1]=min(dx[1],x);dx[0]=max(dx[0],x);
			dy[1]=min(dy[1],y);dy[0]=max(dy[0],y);
			if (dx[0]-dx[1]+1>n||dy[0]-dy[1]+1>m)
			{
				dx[0]=dx[1]=dy[0]=dy[1]=0;
				x=y=0;
				for (int j=1;j<i;j++)
				{
					if (s[j]=='L') y--;
					if (s[j]=='R') y++;
					if (s[j]=='U') x--;
					if (s[j]=='D') x++;
					dx[1]=min(dx[1],x);dx[0]=max(dx[0],x);
					dy[1]=min(dy[1],y);dy[0]=max(dy[0],y);
				}
				printf("%d %d\n",-dx[1]+1,-dy[1]+1);
				bl=0;
				break;
			}
		}
		if (!bl) continue;
		if (x<0) printf("%d ",n-dx[0]);
		else printf("%d ",-dx[1]+1);
		if (y<0) printf("%d\n",m-dy[0]);
		else printf("%d\n",-dy[1]+1);
	}
}