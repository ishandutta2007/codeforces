#include<map>
#include<cstdio>
#include<cctype>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
	int c,x,f;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=5e5+19;
typedef long long LL;
map<LL,int> M;
LL S[N],Ans;
int n;

int main()
{
	n=IN();
	For(i,1,n+1) S[i]=S[i-1]+IN();
	for (int i=n-1;i;i--)
	{
		if (S[i]==S[n]/3) Ans+=M[S[i]+S[n]/3];
		if (S[n]-S[i]==S[n]/3) M[S[i]]++;
	}
	printf("%I64d\n",Ans);
}