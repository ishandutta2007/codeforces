#include<cstdio>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

int cnt[26];
char s[200000+19];
int n,Ans;

int main()
{
	scanf("%d",&n);n--;
	scanf("%s",s);
	For(i,0,n)
	{
		cnt[s[2*i]-'a']++;
		if (!cnt[s[2*i+1]-'A']) Ans++;else cnt[s[2*i+1]-'A']--;
	}
	printf("%d\n",Ans);
}