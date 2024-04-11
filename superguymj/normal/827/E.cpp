#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=500005;
int n,stk[N],top,ans[N],tot;
char s[N];

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;	
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve() 
{
	n=getint(),scanf("%s",s),tot=0;
	rep(k,1,n-1)
	{
		for(int i=0,j=k; j<n; ++i,++j) 
		{
			if(s[i]!=s[j]) 
			{
				if(s[i]=='?') s[i]=s[j],stk[++top]=i;
				else if(s[j]=='?') s[j]=s[i],stk[++top]=j;
				else break;
			}
			if(j==n-1) ans[++tot]=k;
		}
		while(top) s[stk[top--]]='?';
	}
	ans[++tot]=n,printf("%d\n",tot);
	rep(i,1,tot) printf("%d ",ans[i]);
	puts("");
}
int main()
{
	for(int T=getint(); T--; solve());
	return 0;
}