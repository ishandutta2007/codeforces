#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
int t;
bool jdg,vis[255];
char s[10];

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		bool jdg=1;
		memset(vis,0,sizeof(vis));
		rep(i,1,6) if(s[i]>'a' && s[i]<'z') vis[s[i]]=1;
			else if(vis[s[i]-'A'+'a']==0) jdg=0;
		if(jdg) puts("YES");	
		else puts("NO");
	}
	return 0;
}