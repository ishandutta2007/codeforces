#include<cstdio>

using namespace std;

long long i,j,n,m,o;
char s[1000001];
char ch;

int main()
{
	ch=getchar();
	while(ch!=-1&&ch!='\n')s[++o]=ch,ch=getchar();
	for(i=1;i<=o-4;i++)
	{
		if(s[i]=='h'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='v'&&s[i+4]=='y')
			n++;
		if(s[i]=='m'&&s[i+1]=='e'&&s[i+2]=='t'&&s[i+3]=='a'&&s[i+4]=='l')
			m+=n;
	}
	printf("%I64d",m);
}