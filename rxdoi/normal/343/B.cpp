#include<cstdio>
#include<cstring>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=100000+19;
char s[N],S[N];
int t,n;

int main()
{
	scanf("%s",s);n=strlen(s);
	For(i,0,n) if (t&&S[t]==s[i]) t--;else S[++t]=s[i];
	puts(t?"No":"Yes");
}