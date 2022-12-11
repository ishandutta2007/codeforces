#include<cstdio>
#include<cstring>
using namespace std;

const int Maxn=1e4+19,Mod=1e9+7;
char Map[3][Maxn];
int Dp[Maxn][8][2],tmp[Maxn];
int n;

inline int is_0(int x,int Dis) {return ((x>>Dis)&1)==0;}
inline int Get_Dp(int x,int now,int Flag)
{
	int &A=Dp[x][now][Flag];
	if (A^-1) return A;A=0;
	if (x==n) return A=(!now&&Flag);
	now|=tmp[x];
	if (now==7) return A=Get_Dp(x+1,0,Flag);
	if (is_0(now,0)&&is_0(now,1)) A=(A+Get_Dp(x,now|3,Flag||Map[2][x]=='O'))%Mod;
	if (is_0(now,1)&&is_0(now,2)) A=(A+Get_Dp(x,now|6,Flag||Map[0][x]=='O'))%Mod;
	int can=1,nxt_Flag=0,nxt_now=0;
	for (int i=0;i<3;i++)
	{
		if (is_0(now,i)&&!is_0(tmp[x+1],i)) {can=0;break;}
		if (x&&Map[i][x-1]=='O'||Map[i][x+2]=='O') nxt_Flag=1;
		if (is_0(now,i)) nxt_now|=(1<<i);
	}
	if (can) A=(A+Get_Dp(x+1,nxt_now,Flag||nxt_Flag))%Mod;
	return A;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<3;i++) scanf("%s",Map[i]);
	for (int i=0;i<n;i++)
	{
		tmp[i]=7;
		for (int j=0;j<3;j++)
			if (Map[j][i]=='.') tmp[i]-=(1<<j);
	}
	memset(Dp,-1,sizeof(Dp));
	printf("%d\n",Get_Dp(0,0,0));
}