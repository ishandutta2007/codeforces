#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Pb push_back
using namespace std;

const int N=5000+19;
typedef long long LL;
vector<int> V;
char s[N];
int D[N],n;LL Ans,S[N];

LL Calc(int L,int R)
{
	if (L>R) return 0;
	int ts=0,td=0;
	For(i,L,R+1)
		if (i&1) S[++ts]=s[i]-'0';else
		{
			while (s[i]=='+'&&D[td]=='*') S[ts-1]=S[ts]*S[ts-1],td--,ts--;
			D[++td]=s[i];
		}
	while (td) S[ts-1]=D[td--]=='+'?S[ts]+S[ts-1]:S[ts]*S[ts-1],ts--;
	return S[1];
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	V.Pb(0);
	for (int i=2;i<=n;i+=2) if (s[i]=='*') V.Pb(i);
	V.Pb(n+1);
	For(i,0,V.size()) For(j,i+1,V.size())
	{
		LL tmp=Calc(V[i]+1,V[j]-1);int L=V[i],R=V[j];
		while (L>=1&&s[L]=='*') tmp*=(s[L-1]-'0'),L-=2;
		while (R<=n&&s[R]=='*') tmp*=(s[R+1]-'0'),R+=2;
		Ans=max(Ans,tmp+Calc(1,L-1)+Calc(R+1,n));
	}
	printf("%I64d\n",Ans);
}