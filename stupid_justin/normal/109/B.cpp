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
const int N=2e6+5;
const int M=5005;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x);x=(x*x);y>>=1;}return ret;}

int luck[N],n;
void init()
{
	for (int L=1;L<=9;L++)
	{
		//L
		for (int s=0;s<(1LL<<L);s++)
		{
			int tmp=s,TMP=0;
			for (int i=0;i<L;i++)
			{
				TMP+=(4+(tmp&1)*3)*ksm(10,i);
				tmp>>=1;
			}
			luck[++n]=TMP;
		}
	}
}
int pl,pr,vl,vr,k;
double ans;
int calc(int l,int r,int L,int R)
{
	if (r<L || l>R) return 0;
	if (l>r || L>R) return 0;
	if (l>=L && l<=R) return min(r,R)-l+1;
	if (r>=L && r<=R) return r-max(l,L)+1;
	if (l<L && r>R) return R-L+1;
}
signed main()
{
	init();
	luck[++n]=0x3f3f3f3f3f3f3f3f;
	sort(luck+1,luck+n+1);
	cin>>pl>>pr>>vl>>vr>>k;
	for(int i=1;i+k-1<=n;i++)
	{
		if(luck[i]>vr && luck[i]>pr) break;
		int j=i+k-1;
		ans+=calc(luck[i-1]+1,luck[i],pl,pr)*calc(luck[j],luck[j+1]-1,vl,vr);
		ans+=calc(luck[j],luck[j+1]-1,pl,pr)*calc(luck[i-1]+1,luck[i],vl,vr);
		if(k==1) if(calc(pl,pr,luck[i],luck[i]) && calc(vl,vr,luck[i],luck[i])) ans-=1;
	}
	
	ans/=(pr-pl+1);ans/=(vr-vl+1);
	printf("%.12lf\n",ans);
}