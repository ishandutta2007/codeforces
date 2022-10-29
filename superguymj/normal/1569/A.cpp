#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
 
using namespace std;
int n;
char s[100];
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n),scanf("%s",s+1);
		bool jdg=0;	
		rep(i,1,n)
		{
			rep(j,i,n)
			{
				int cnt=0;
				rep(k,i,j) if(s[k]=='a') ++cnt; else --cnt;
				if(cnt==0) {jdg=1,printf("%d %d\n",i,j); break;}
			}
			if(jdg) break;
		}
		if(!jdg) puts("-1 -1");
	}
	return 0;
}