#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

char s[1000001];
int l,n;

int main()
{
	scanf("%s",s+1);
	l=strlen(s+1);
	if(l==1)n=s[l]-'0';
	else n=(s[l-1]-'0')*10+(s[l]-'0');
	n%=4;
	printf("%d",((int)(pow(1,n)+pow(2,n)+pow(3,n)+pow(4,n)))%5);
}