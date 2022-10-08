#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100010
char s[N],t[N];int n;
int main()
{
	scanf("%s",s),n=strlen(s);
	t[n-1]=s[n-1];
	for(int i=n-2;i>=0;i--)t[i]=max(t[i+1],s[i]);
	for(int i=0;i<n;i++)if(s[i]==t[i])putchar(s[i]);
	puts("");
	return 0;
}