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
const int N=105;
const double e=2.7182818284590452353602874713527;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}

int n,k,p;
double ans;
double l,r,R,dp[N][N],P[N];
struct B{double x,y;}b[N];
double dis(double x,double y){return sqrt((x-b[0].x)*(x-b[0].x)+(y-b[0].y)*(y-b[0].y));}
double exp(double a){return pow(e,a);}
double calc(double D){if(D<=R) return 1.0;else return exp(1.0-D*D/(R*R));}
bool check(double mid)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1.0;
    R=mid;
    for (int i=1;i<=n;i++)
    P[i]=1.0-calc(dis(b[i].x,b[i].y));
    for (int i=1;i<=n;i++)
	{
        dp[i][0]=dp[i-1][0]*P[i];
        for (int j=1;j<=i;j++)
            dp[i][j]=dp[i-1][j]*P[i]+dp[i-1][j-1]*(1.0-P[i]);
    }
    double sum=0.0;
    for (int i=0;i<k;i++) sum+=dp[n][i];
    return sum<=(p+0.0)/1000.0;
}
signed main()
{
    rd(n);rd(k);rd(p);
    scanf("%lf%lf",&b[0].x,&b[0].y);
    for (int i=1;i<=n;i++)
	{
        scanf("%lf%lf",&b[i].x,&b[i].y);
        r=max(r,dis(b[i].x,b[i].y));
    }
    while(r-l>=1e-6)
	{
        double mid=(l+r)/2.0;
        if(check(mid))
        {
        	ans=mid;//mid 
			r=mid;
		}
        
        else
        l=mid;
    }
    printf("%.12lf\n",ans);
}