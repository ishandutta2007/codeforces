#include<cstdio>
#include<cstring>
using namespace std;

const int M=40+5;
int A[M][M],s[M][M];
int ss[M][M][M][M],Ans[M][M][M][M];
int n,m,Q,x1,y1,x2,y2;
char c[M];

int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",c);
		for (int j=1;j<=m;j++) s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+c[j-1]-'0';
	}
	for (int Up=1;Up<=n;Up++)
		for (int Dn=Up;Dn<=n;Dn++)
			for (int Le=1;Le<=m;Le++)
				for (int Ri=Le;Ri<=m;Ri++)
				{
					int x=s[Dn][Ri]-s[Dn][Le-1]-s[Up-1][Ri]+s[Up-1][Le-1];
					if (x) break;
					ss[Up][Le][Dn][Ri]=1;
				}
	for (int Dn=1;Dn<=n;Dn++)
		for (int Ri=1;Ri<=m;Ri++)
			for (int Up=Dn;Up;Up--)
				for (int Le=Ri;Le;Le--)
					ss[Up][Le][Dn][Ri]+=ss[Up+1][Le][Dn][Ri]+ss[Up][Le+1][Dn][Ri]-ss[Up+1][Le+1][Dn][Ri];
	for (int Up=1;Up<=n;Up++)
		for (int Dn=Up;Dn<=n;Dn++)
			for (int Le=1;Le<=m;Le++)
				for (int Ri=Le;Ri<=m;Ri++)
					Ans[Up][Le][Dn][Ri]=Ans[Up][Le][Dn][Ri-1]+Ans[Up][Le][Dn-1][Ri]-Ans[Up][Le][Dn-1][Ri-1]+ss[Up][Le][Dn][Ri];
	while (Q--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",Ans[x1][y1][x2][y2]);
	}
}