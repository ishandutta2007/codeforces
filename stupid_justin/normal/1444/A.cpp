

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
const int N=3e5+5;
const int M=2005;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int p,q,ans;
int prim[N],vis[N],cnt;
int num[N],CNT[N],Cnt;
void init()
{
    for (int i=2;i<N;i++)
    {
        if (!vis[i]) prim[++cnt]=i;
        for (int j=1;j<=cnt;j++)
        {
            if (prim[j]*i>=N) break;
            vis[prim[j]*i]=1;
            if (i%prim[j]==0) break;
        }
    }
}
signed main()
{
    init();
    int T;
    cin>>T;
    while (T--)
    {
        cin>>p>>q;
        int x=p;
        if (p%q==0)
        {
            {
                //q
                Cnt=0;
                for (int i=1;i<=cnt;i++)
                {
                    if (q%prim[i]==0)
                    {
                        num[++Cnt]=prim[i];
                        CNT[Cnt]=0;
                        while (q%prim[i]==0)
                        {
                            CNT[Cnt]++;
                            q/=prim[i];
                        }
                    }
                }
                if (q!=1) num[++Cnt]=q,CNT[Cnt]=1;
                //qp
                //q
                //
                int chushu=p;
                for (int i=1;i<=Cnt;i++)
                {
                    x=p;
                    int TMP=0;
                    while (x%num[i]==0)
                    {
                        x/=num[i];
                        TMP++;
                    }
                    //pTMPnum[i]
                    chushu=min(chushu,ksm(num[i],TMP-CNT[i]+1,0x3f3f3f3f3f3f3f3f));
                }
                cout<<p/chushu<<endl;
                for (int i=1;i<=Cnt;i++) num[i]=CNT[i]=0;
                Cnt=0;
            }
        }
        else cout<<x<<endl;
    }    
}