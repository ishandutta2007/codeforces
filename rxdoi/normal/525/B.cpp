#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x;
	while (!isdigit(c=getchar()));x=c-'0';
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=2e5+19;
char s[N];
int m,Len,A[N];

int main()
{
	scanf("%s%d",s,&m);Len=strlen(s);
	For(i,0,m) A[IN()-1]++;
	for (int i=0,_=0;i<=(Len-1)/2;i++)
	{
		_+=A[i];
		if (_&1) swap(s[i],s[Len-i-1]);
	}
	printf("%s\n",s);
}