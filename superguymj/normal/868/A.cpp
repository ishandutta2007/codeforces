#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
bool vis1,vis2;
int n;
char ch[10],s[10];

int main()
{
	scanf("%s",ch);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		if(s[0]==ch[0] && s[1]==ch[1])
		{
			puts("YES");
			return 0;
		}
		if(s[0]==ch[1]) vis1=1;
		if(s[1]==ch[0]) vis2=1;
		if(vis1 && vis2)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}