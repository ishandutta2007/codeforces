#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=20;
char s[Maxn];
int k,Len;

inline void Doit(int x,int k)
{
	if (k<=0||x>=Len) return;
	int Max=0,ID;
	for (int i=x;i<=x+k&&i<Len;i++) if (s[i]>Max) Max=s[i],ID=i;
	for (int i=ID;i>x;i--) s[i]=s[i-1];s[x]=Max;
	Doit(x+1,k-(ID-x));
}

int main()
{
	scanf("%s%d",s,&k);Len=strlen(s);
	Doit(0,k);
	printf("%s\n",s);
}