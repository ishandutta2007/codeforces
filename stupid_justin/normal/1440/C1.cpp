// *............    ..=^.,]]/O].*..[,OOO@@OO@@@@@@@@@@@@@@@@@@@@OO
// .........*=o`...,/@@@@@@@@@@@@@@]`...*..*=OO@@@@@@@@@@@O@@@@OOO
// ..,[`..,OO^..oO@@@@@@@@@@@@@@@@@@@Ooooo`]O@@@O@@@@@@@@@@@@@@@@
// O@@@@@OOOOOOO@@@@@@@@@@@@@@@@@@@@@@@O/`..[[[..[O/=O@O@@@O@@@@@@
// @@@@@@@@@@@O@@@@@@@@@@@@@@@@@@@O@@@@@O@@OOO]]/OO@@OO@@@@OOOOOOO
// ooOooo/[oooO@@@@@@@@@@@@OOOooOOoO@@@@O@@@OO@@@@@@@@@@@O@@@@@@@@
// OOOOOOOoOOOO@@@@OOOO/***......*,OOOOOOOOOOO@O\*/OOOOOOOOOO@@@@O
// ...........=@@@Ooo\***..........,\oooo*..*[[[ooooOoOOOOOOOOOO/[
// ...........=OOOoooo^****..........,\oo.........................
// ............@OO****...**............*..o.......................
// ............=/*,]/OOO]]]]oO/..................................
// ............\^*o`**/oOO^.*OO@[[[[`.........,]@@@@@@@@@@@@@@@@@@
// .............o*\/[]]]/*.........   ....../@@[[[[[[[[[[[[[[[[[[[
// .............**.............`...........=@^./@@`............./@
// ..............**....=^......=O]*........@@.=@@@@............=@@
// ...............\**,/OoO@@OO`.*oO\*.... .@@`.@@@@............=@@
// ...............,oooOO\]/O/OOO@OOo*..... ,@\.,@@@............=@@
// **,`**.*****.***=OooOOOO\]]O[..=o`....   ,@@`..[............,`.
// .*......,****..***OOOoOO]]OO^....*...      ,@@@\............=@@
// [***.....*......*...\O^,,[[.....****.         \@`..........,@@^
// ....................  .\Oo]]]]]oooo^           \@@]]....]]@@@`.
// **.....**.*****..   .  =OOOOOOOOOO.       ...     \@^...@@[....
// ........*.*.... .   .  ,,OOOOOOO/       ..     ,@@@@^...@@@@\**
// ..........*.*.  .  ,@@@@@@@@@@@@@@@@@`...  ./@@@@..........=@@@
// *.,`,*****`..  ..  ,@O\ \O@@@@@@O`/O@`...  @@OOOOOOOOOOOOOOOOOO
// .***,[`*.,*..  .. ...@O\ \O@@@@O`=@@.......@@@@@@@@@@@@@@@@@@@@
// ]***..*.... . ...     \@O =O\\O =@/.... ..`,`..................
// **..****.*. .....      @^..]]]..,@^... .... .       .          
// ******.**` ......     =^.=o].=o\.=@.. .....     .              
// *..*.***.  ......     =^.\o[.,oo.=@`...                        
// `..*/***.  ......     .@`.,[o/[.,@^.....                  ..   
// *]*..***.   ...........O@@\]]]/@@`./[`          ......         
#include<bits/stdc++.h>
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=2005+5;
const int M=5005;
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n,m,k;
int a[N][N];
struct dish
{
	int a,b;
}D[N];
bool cmp(dish x,dish y)
{
	return x.a<y.a;
}
struct op
{
	int x[3],y[3];
	void Out()
	{
		for (int i=0;i<=2;i++) printf("%lld %lld ",x[i],y[i]);
		printf("\n");
	}
}OP[N];
void makeop(int X,int Y)
{
	int cnt=0;
	for (int i=X;i<=X+1;i++)
	{
		for (int j=Y;j<=Y+1;j++)
		{
			if (a[i][j]==1) cnt++;
		}
	}
	if (cnt==0)
	{
		return;
	}
	if (cnt==3)
	{
		k++;
		int Cnt=0;
		for (int i=X;i<=X+1;i++)
		{
			for (int j=Y;j<=Y+1;j++)
			{
				if (a[i][j]==1) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					Cnt++;
					a[i][j]=0;
				}
			}
		}
		return;
	}
	if (cnt==2)
	{
		k++;
		int Cnt=0,cnt0=0,cnt1=0;
		for (int i=X;i<=X+1;i++)
		{
			for (int j=Y;j<=Y+1;j++)
			{
				if (a[i][j]==1 && cnt0==0) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=0;
					cnt0++;Cnt++;
				}else
				if (a[i][j]==0 && cnt1<=1) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=1;
					cnt1++;Cnt++;
				}
			}
		}
		makeop(X,Y);
	}
	if (cnt==1)
	{
		k++;
		int Cnt=0,cnt0=0,cnt1=0;
		for (int i=X;i<=X+1;i++)
		{
			for (int j=Y;j<=Y+1;j++)
			{
				if (a[i][j]==1 && cnt0==0) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=0;
					cnt0++;
					Cnt++;
				}else
				if (a[i][j]==0 && cnt1<=1) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=1;
					cnt1++;
					Cnt++;
				}
			}
		}
		makeop(X,Y);
	}
	if (cnt==4)
	{
		k++;
		int Cnt=0,cnt0=0,cnt1=0;
		for (int i=X;i<=X+1;i++)
		{
			for (int j=Y;j<=Y+1;j++)
			{
				if (a[i][j]==1 && cnt0<=2) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=0;
					cnt0++;
					Cnt++;
				}else
				if (a[i][j]==0 && cnt1<=-1) 
				{
					OP[k].x[Cnt]=i,OP[k].y[Cnt]=j;
					a[i][j]=1;
					cnt1++;
					Cnt++;
				}
			}
		}
		makeop(X,Y);
	}
}
string str;
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		k=0;
		for (int i=1;i<=n;i++)
		{
			cin>>str;
			for (int j=1;j<=m;j++) 
			{
				a[i][j]=str[j-1]-'0';
			}
		}
        for (int i=1;i<=n-1;i+=2)
        {
        	for (int j=1;j<=m-1;j+=2)
        		makeop(i,j);
		}
		for (int i=1;i<=m-1;i+=2) makeop(n-1,i);
		for (int i=1;i<=n-1;i+=2) makeop(i,m-1);
		makeop(n-1,m-1);
		cout<<k<<endl;
		for (int i=1;i<=k;i++) OP[i].Out();
	}
}