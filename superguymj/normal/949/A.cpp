#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<vector>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define pb push_back 
using namespace std;
const int N=200005;
char s[N];
int n,cnt,tot,stk0[N],stk1[N];
vector <int> p[N];

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	rep(i,1,n) if(s[i]=='1') --cnt; else ++cnt;
	if(cnt<=0) return puts("-1"),0;	
	rep(i,1,n)
		if(s[i]=='1')
		{
			if(stk0[0]==0) return puts("-1"),0;
			p[stk0[*stk0]].pb(i);
			stk1[++*stk1]=stk0[*stk0],--*stk0;
		}
		else
		{
			if(stk1[0]==0)
			{
				stk0[++*stk0]=++tot,p[tot].pb(i);
				if(tot>cnt) return puts("-1"),0;
			}
			else
			{
				p[stk1[*stk1]].pb(i);
				stk0[++*stk0]=stk1[*stk1],--*stk1;
			}
		}
	
	printf("%d\n",tot);
	rep(i,1,tot)
	{
		int siz=p[i].size();
		printf("%d",siz);
		rep(j,0,siz-1) printf(" %d",p[i][j]);
		puts("");
	}
	return 0;
}