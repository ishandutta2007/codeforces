#include<cstdio>
using namespace std;

const int N=500+19;
int n;
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=0;i<n;i++)
		for (int j=1;i+j+j+j+j<n;j++)
			if (s[i]=='*'&&s[i+j]=='*'&&s[i+j+j]=='*'&&s[i+j+j+j]=='*'&&s[i+j+j+j+j]=='*')
				return puts("yes"),0;
	puts("no");
}