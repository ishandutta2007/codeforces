#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,now,a1,b1,c1,a2,b2,c2,id1,id2;
int id[55][55][55];

void F1(){id[++a1][b1][c1]=++id1;}
void B1(){id[--a1][b1][c1]=++id1;}
void U1(){id[a1][++b1][c1]=++id1;}
void D1(){id[a1][--b1][c1]=++id1;}
void L1(){id[a1][b1][--c1]=++id1;}
void R1(){id[a1][b1][++c1]=++id1;}
void F2(){id[++a2][b2][c2]=--id2;}
void B2(){id[--a2][b2][c2]=--id2;}
void U2(){id[a2][++b2][c2]=--id2;}
void D2(){id[a2][--b2][c2]=--id2;}
void L2(){id[a2][b2][--c2]=--id2;}
void R2(){id[a2][b2][++c2]=--id2;}

int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	id[a1=2][b1=1][c1=1]=id1=1;
	id[a2=1][b2=1][c2=1]=id2=0;
	U2();R2();D2();
	R1();U1();L1();
	
	for(now=2;now<n;++now)
	{
		if(now%2)
		{
			F1();
			for(i=1;i<now;++i)L1();
			D1();
			for(i=1;i<=now;++i)
			{
				for(j=2;j<now;++j)if(i%2)D1();else U1();
				R1();
			}
			for(i=1;i<=now;++i)
			{
				for(j=1;j<now;++j)if(i%2)B1();else F1();
				U1();
			}
			for(i=1;i<=now;++i)
			{
				for(j=1;j<=now;++j)if(i%2)L1();else R1();
				if(i!=now)F1();
			}
		}
		else
		{
			F1();
			for(i=1;i<=now;++i)
			{
				for(j=1;j<now;++j)if(i%2)D1();else U1();
				R1();
			}
			for(i=1;i<=now;++i)
			{
				for(j=1;j<now;++j)if(i%2)D1();else U1();
				if(i!=now)B1();
			}
			U1();
			for(i=1;i<=now;++i)
			{
				for(j=1;j<=now;++j)if(i%2)L1();else R1();
				if(i!=now)F1();
			}
		}
		
		if(now%2)
		{
			U2();
			for(i=1;i<=now;++i)R2();
			for(i=1;i<=now;++i)D2();
		}
		else
		{
			R2();
			for(i=1;i<=now;++i)U2();
			for(i=1;i<=now;++i)L2();
		}
	}
	
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			for(k=1;k<=n;++k)
			{
				printf("%d",id[i][j][k]-id2+1);
				if(k!=n)printf(" ");
			}
			printf("\n");
		}
		if(i!=n)printf("\n");
	}
}