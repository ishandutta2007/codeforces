#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1000000+19;
char s[N];
int Ans,cnt,S,n;

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for (S=1;S<=n&&s[S]=='F';S++);
	For(i,S,n+1)
		if (s[i]=='F') Ans=max(Ans+1,cnt);else cnt++;
	printf("%d\n",Ans);
}