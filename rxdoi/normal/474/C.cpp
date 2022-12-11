#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
struct Point
{
	int x,y;
} A[6],B[6],tmp[6];
int c[6],n;
LL cc[6][6];

inline LL sqr(LL x) {return x*x;}
inline Point turn(Point A,Point B,int c)
{
	int x=A.x-B.x,y=A.y-B.y;
	if (c==0) return A;
	if (c==1) return (Point){B.x-y,B.y+x};
	if (c==2) return (Point){B.x-x,B.y-y};
	if (c==3) return (Point){B.x+y,B.y-x};
}
inline int check()
{
	if (tmp[1].x==tmp[2].x&&tmp[1].y==tmp[2].y) return 0;
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=4;j++)
			if (i!=j) cc[i][j]=sqr(tmp[i].x-tmp[j].x)+sqr(tmp[i].y-tmp[j].y);
				else cc[i][j]=0;
		sort(cc[i]+1,cc[i]+5);
		if (cc[i][2]!=cc[i][3]) return 0;
		if (cc[i][4]<=cc[i][2]) return 0;
	}
	if (cc[1][2]!=cc[2][2]||cc[2][2]!=cc[3][2]||cc[3][2]!=cc[4][2]) return 0;
	if (cc[1][4]!=cc[2][4]||cc[2][4]!=cc[3][4]||cc[3][4]!=cc[4][4]) return 0; 
	return 1;
}

int main()
{
	scanf("%d",&n);
	while (n--)
	{
		int Ans=(1<<30)-1;
		for (int i=1;i<=4;i++) scanf("%d%d%d%d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
		memset(c,0,sizeof(c));
		while (c[0]==0)
		{
			int x=4,num=0;
			for (int i=1;i<=4;i++) tmp[i]=turn(A[i],B[i],c[i]);
			if (check())
			{
				for (int i=1;i<=4;i++) num+=c[i];
				Ans=min(Ans,num);
			}
			while (c[x]==3) x--;
			c[x]++;
			for (int i=x+1;i<=4;i++) c[i]=0;
		}
		printf("%d\n",(Ans==(1<<30)-1)?-1:Ans);
	}
}