
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
#define rd(x) x=read()
#define int long long
using namespace std;
const int N=1e6+5;
const int maxn=1e7+5;
const int inf=0x3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while (ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int n,q,ans;
int app[N];
int a[N];
int pos[N];
int ANS[N];
struct Query{int l,r,id;}Q[N];
inline bool cmp(Query a,Query b){return pos[a.l]^pos[b.l]?pos[a.l]<pos[b.l]:(pos[a.l]&1)?a.r<b.r:a.r>b.r;}
inline bool CMP(Query a,Query b){return a.id<b.id;}
inline void add(int &x){if (x>n) return;if (app[x]==x) ans--;app[x]++;if (app[x]==x) ans++;}
inline void del(int &x){if (x>n) return;if (app[x]==x) ans--;app[x]--;if (app[x]==x) ans++;}
signed main()
{
    rd(n);rd(q);
    for (register int i=1;i<=n;i++) rd(a[i]);
    for (register int i=1;i<=n;i++) pos[i]=i/1800;
    for (register int i=1;i<=q;i++)
    {
        rd(Q[i].l);rd(Q[i].r);
        Q[i].id=i;
    }
    sort(Q+1,Q+q+1,cmp);
    //for (register int i=1;i<=n;i++) app[i]=0;
    for (register int i=1,l=1,r=0;i<=q;i++)
    {
        while (r<Q[i].r){add(a[r+1]);r++;}
        while (r>Q[i].r){del(a[r]);r--;}
        while (l<Q[i].l){del(a[l]);l++;}
        while (l>Q[i].l){add(a[l-1]);l--;}
        ANS[Q[i].id]=ans;
    }
    for (int i=1;i<=q;i++) cout<<ANS[i]<<"\n";
}