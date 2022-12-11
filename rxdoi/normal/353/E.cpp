#include<cstdio>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

const int N=1e6+19;
char s[N*3];
int n,t,p;

int SPJ(int L,int R)
{
	For(i,L,R) if (s[i]==s[i+1]) return i;
	return -1;
}
int Solve(int L,int R)
{
	if (L>R) return 0;
	if ((p=t=SPJ(L,R))==-1) return (R-L+2)/2;
	for (;s[t]==s[t+1];t++);
	return (p-L+1)/2+1+Solve(t+2,R);
}

int main()
{
	scanf("%s",s);n=strlen(s);
	For(i,0,n) s[i+n]=s[i+n+n]=s[i];
	if ((p=t=SPJ(n,n+n))==-1) return printf("%d\n",n/2),0;
	for (;s[p]==s[p+1];p++);
	for (;s[t-1]==s[t];t--);
	printf("%d\n",Solve(p+2,t+n-1)+1);
}