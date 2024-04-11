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
string str;
int ans[N];
int L[N],R[N];
int U[N],D[N];
signed main()
{
	int T;
	cin>>T;
	while (T--)
	{
		rd(n);
		for (int i=0;i<=9;i++) ans[i]=0;
		for (int i=1;i<=n;i++)
		{
			cin>>str;
			for (int j=1;j<=n;j++) a[i][j]=str[j-1]-'0';
		}
		for (int i=0;i<=9;i++) U[i]=n+1,D[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				U[a[i][j]]=min(U[a[i][j]],i);
				D[a[i][j]]=max(D[a[i][j]],i);
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=0;j<=9;j++) L[j]=n+1,R[j]=0;
			for (int j=1;j<=n;j++) 
			{
				L[a[i][j]]=min(L[a[i][j]],j);
				R[a[i][j]]=max(R[a[i][j]],j);
			}
			for (int j=0;j<=9;j++)
			{
				ans[j]=max(ans[j],(R[j]-L[j])*max(i-1,n-i));
				int H=max(i-U[j],D[j]-i);
				int W=max(R[j]-1,n-L[j]);
				if (H<0) H=0;
				if (W<0) W=0;
				ans[j]=max(ans[j],W*H);
			}
		}
		for (int i=0;i<=9;i++) L[i]=n+1,R[i]=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				L[a[i][j]]=min(L[a[i][j]],j);
				R[a[i][j]]=max(R[a[i][j]],j);
			}
		}
		for (int j=1;j<=n;j++)
		{
			for (int i=0;i<=9;i++) U[i]=n+1,D[i]=0;
			for (int i=1;i<=n;i++)
			{
				U[a[i][j]]=min(U[a[i][j]],i);
				D[a[i][j]]=max(D[a[i][j]],i);
			}
			for (int i=0;i<=9;i++)
			{
				ans[i]=max(ans[i],(D[i]-U[i])*max(j-1,n-j));
				int W=max(j-L[i],R[i]-j);
				int H=max(D[i]-1,n-U[i]);
				if (H<0) H=0;
				if (W<0) W=0;
				ans[i]=max(ans[i],H*W);
			}
		}
		for (int i=0;i<=9;i++) printf("%lld ",ans[i]);
		cout<<endl;
	}
}