#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int T;
char s[N];
int len;
void solve()
{
	scanf("%s",s+1);
	len=0;
	for (len=1;s[len+1];len++);
	for (int i=len;i>1;i--)
		if (s[i]-'0'+s[i-1]-'0'>=10)
		{
			s[i]=(s[i]-'0'+s[i-1]-'0')%10+'0';
			s[i-1]='1';
			return;
		}
	for (int i=1;i<len;i++)
		if (s[i+1]!='0')
		{
			s[i]=(s[i]-'0'+s[i+1]-'0')%10+'0';
			for (int j=i+1;j<len;j++)
				s[j]=s[j+1];
			s[len]=0;
			return;
		}
	s[len]=0;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		solve();
		printf("%s\n",s+1);
	}
	return 0;
}