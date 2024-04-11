#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool Hash[2000005];
int T,i,a1,a2,a3,b1,b2,b3,c1,c2,c3,ans,aim;

void dfs(int A,int B,int C,int Am,int Bm,int Cm,int As,int Bs,int Cs,int Ah,int Bh,int Ch)
{
	int hash=(((((((((((((((((((A*45+B)*45+C)*2+Am)<<1)+Bm)<<1)+Cm)<<1)+As)<<1)+Bs)<<1)+Cs)<<2)+Ah)<<2)+Bh)<<2)+Ch)%1000007;
	if(Hash[hash])return;
	Hash[hash]=true;
	
	if(A>ans)ans=A;
	if(B>ans)ans=B;
	if(C>ans)ans=C;
	
	int i;
	if(Am&&A!=B&&A!=C)
	{
		for(i=1;i<=a2;++i)
		{
			if(A+i!=B&&A+i!=C)dfs(A+i,B,C,0,Bm,Cm,As,Bs,Cs,Ah,Bh,Ch);
			if(A-i!=B&&A-i!=C&&A>=i)dfs(A-i,B,C,0,Bm,Cm,As,Bs,Cs,Ah,Bh,Ch);
		}
	}
	if(Bm&&B!=A&&B!=C)
	{
		for(i=1;i<=b2;++i)
		{
			if(B+i!=A&&B+i!=C)dfs(A,B+i,C,Am,0,Cm,As,Bs,Cs,Ah,Bh,Ch);
			if(B-i!=A&&B-i!=C&&B>=i)dfs(A,B-i,C,Am,0,Cm,As,Bs,Cs,Ah,Bh,Ch);
		}
	}
	if(Cm&&C!=A&&C!=B)
	{
		for(i=1;i<=c2;++i)
		{
			if(C+i!=A&&C+i!=B)dfs(A,B,C+i,Am,Bm,0,As,Bs,Cs,Ah,Bh,Ch);
			if(C-i!=A&&C-i!=B&&C>=i)dfs(A,B,C-i,Am,Bm,0,As,Bs,Cs,Ah,Bh,Ch);
		}
	}
	
	if(As&&Bh!=1&&Ch!=1)
	{
		if(Ah)
		{
			for(i=1;i<=a3;++i)
			{
				if(Ah==2)
				{
					if(A+i!=C)
					{
						if(Bh)dfs(A,A+i,A+i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
						else dfs(A,A+i,C,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
					}
					if(A-i!=C&&A-i>=0)
					{
						if(Bh)dfs(A,A-i,A-i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
						else dfs(A,A-i,C,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
					}
				}
				else
				{
					if(A+i!=B)
					{
						if(Ch)dfs(A,A+i,A+i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
						else dfs(A,B,A+i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
					}
					if(A-i!=B&&A-i>=0)
					{
						if(Ch)dfs(A,A-i,A-i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
						else dfs(A,B,A-i,Am,Bm,Cm,0,Bs,Cs,0,Bh,Ch);
					}
				}
			}
		}
		else
		{
			if((B==A-1||B==A+1)&&Ch!=2)
			{
				if(Bh)dfs(A,A,A,Am,Bm,Cm,As,Bs,Cs,2,Bh,Ch);
				else dfs(A,A,C,Am,Bm,Cm,As,Bs,Cs,2,Bh,Ch);
			}
			if((C==A-1||C==A+1)&&Bh!=3)
			{
				if(Ch)dfs(A,A,A,Am,Bm,Cm,As,Bs,Cs,3,Bh,Ch);
				else dfs(A,B,A,Am,Bm,Cm,As,Bs,Cs,3,Bh,Ch);
			}
		}
	}
	
	if(Bs&&Ah!=2&&Ch!=2)
	{
		if(Bh)
		{
			for(i=1;i<=b3;++i)
			{
				if(Bh==1)
				{
					if(B+i!=C)
					{
						if(Ah)dfs(B+i,B,B+i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
						else dfs(B+i,B,C,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
					}
					if(B-i!=C&&B-i>=0)
					{
						if(Ah)dfs(B-i,B,B-i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
						else dfs(B-i,B,C,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
					}
				}
				else
				{
					if(B+i!=A)
					{
						if(Ch)dfs(B+i,B,B+i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
						else dfs(A,B,B+i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
					}
					if(B-i!=A&&B-i>=0)
					{
						if(Ch)dfs(B-i,B,B-i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
						else dfs(A,B,B-i,Am,Bm,Cm,As,0,Cs,Ah,0,Ch);
					}
				}
			}
		}
		else
		{
			if((A==B-1||A==B+1)&&Ch!=1)
			{
				if(Ah)dfs(B,B,B,Am,Bm,Cm,As,Bs,Cs,Ah,1,Ch);
				else dfs(B,B,C,Am,Bm,Cm,As,Bs,Cs,Ah,1,Ch);
			}
			if((C==B-1||C==B+1)&&Ah!=3)
			{
				if(Ch)dfs(B,B,B,Am,Bm,Cm,As,Bs,Cs,Ah,3,Ch);
				else dfs(A,B,B,Am,Bm,Cm,As,Bs,Cs,Ah,3,Ch);
			}
		}
	}
	
	if(Cs&&Ah!=3&&Bh!=3)
	{
		if(Ch)
		{
			for(i=1;i<=c3;++i)
			{
				if(Ch==1)
				{
					if(C+i!=B)
					{
						if(Ah)dfs(C+i,C+i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
						else dfs(C+i,B,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
					}
					if(C-i!=B&&C-i>=0)
					{
						if(Ah)dfs(C-i,C-i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
						else dfs(C-i,B,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
					}
				}
				else
				{
					if(C+i!=A)
					{
						if(Bh)dfs(C+i,C+i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
						else dfs(A,C+i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
					}
					if(C-i!=A&&C-i>=0)
					{
						if(Bh)dfs(C-i,C-i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
						else dfs(A,C-i,C,Am,Bm,Cm,As,Bs,0,Ah,Bh,0);
					}
				}
			}
		}
		else
		{
			if((A==C-1||A==C+1)&&Bh!=1)
			{
				if(Ah)dfs(C,C,C,Am,Bm,Cm,As,Bs,Cs,Ah,Bh,1);
				else dfs(C,B,C,Am,Bm,Cm,As,Bs,Cs,Ah,Bh,1);
			}
			if((B==C-1||B==C+1)&&Ah!=2)
			{
				if(Bh)dfs(C,C,C,Am,Bm,Cm,As,Bs,Cs,Ah,Bh,2);
				else dfs(A,C,C,Am,Bm,Cm,As,Bs,Cs,Ah,Bh,2);
			}
		}
	}
}

int main()
{
	while(scanf("%d%d%d%d%d%d%d%d%d",&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3)!=EOF)
	{
		for(i=0;i<=1000007;++i)Hash[i]=false;
		ans=0;
		a1+=2;b1+=2;c1+=2;
		dfs(a1,b1,c1,1,1,1,1,1,1,0,0,0);
		printf("%d\n",ans-2);
	}
}