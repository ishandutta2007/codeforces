#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

bool v[26];
char s[100+19];
int j,k,Len;

int main()
{
	scanf("%d%s",&k,s);Len=strlen(s);
	For(i,0,Len) if (!v[s[i]-'a']) v[s[i]-'a']=1,j++;
	if (j<k) return puts("NO"),0;
	For(i,0,26) v[i]=0;
	puts("YES");
	For(i,0,Len)
	{
		if (k&&!v[s[i]-'a'])
		{
			if (i) puts("");
			v[s[i]-'a']=1,k--;
		}
		putchar(s[i]);
	}
	puts("");
}