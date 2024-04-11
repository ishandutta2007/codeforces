#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e6+19,Mod=1e9+7;
char s[Maxn];
int n,Ans,F[Maxn][2][2];

int main()
{
	scanf("%s",s);
	int Len=strlen(s);
	F[0][0][1]=F[0][0][0]=1;
	for (int i=1;i<=Len;i++)
	{
		int ch=s[i-1];
		if (ch=='?'||ch=='*')
		{
			(F[i][1][0]+=((F[i-1][0][1]+F[i-1][1][1])%Mod))%=Mod;
			(F[i][1][1]+=((F[i-1][0][1]+F[i-1][1][1])%Mod))%=Mod;
		}
		if (ch=='?'||ch=='0') (F[i][0][0]+=F[i-1][0][0])%=Mod;
		if (ch=='?'||ch=='1') 
		{
			(F[i][0][1]+=F[i-1][0][0])%=Mod;
			(F[i][0][0]+=F[i-1][1][0])%=Mod;
		}
		if (ch=='?'||ch=='2') (F[i][0][1]+=F[i-1][1][0])%=Mod;
	}
	printf("%d\n",(F[Len][1][0]+F[Len][0][0])%Mod);
}