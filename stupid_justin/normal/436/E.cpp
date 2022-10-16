
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
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define rd(x) x=read()
using namespace std;
const int N=1e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
int n,m,ans;
int a[N],b[N];
int vis[N];
int res[N];
priority_queue<pii> one,two;
void clear(priority_queue<pii> &x) {while (x.size() && vis[x.top().se]) x.pop();}
signed main()
{
    rd(n);rd(m);a[0]=b[0]=inf;
    for (int i=1;i<=n;i++) {rd(a[i]);rd(b[i]);}
    //
    //a_ib_i-a_i
    //
    //21
    //vis
    //21
    //
    //
    //
    for (int i=n+1;i<=2*n;i++) a[i]=b[i-n]-a[i-n];
    for (int i=1;i<=n;i++) one.push(mp(-a[i],i));//->
    for (int i=1;i<=n;i++) two.push(mp(-b[i],i));//->
    for (int i=1;i<=m;i++)
    {
        int id1=0,id2=0,id3=0;
        clear(one);clear(two);
        id1=one.top().se;one.pop();clear(one);
        if (i<=m-1 && two.size())
        {
            id2=one.top().se;
            id3=two.top().se;
            if (a[id1]+a[id2]>b[id3]) {one.push(mp(-a[id1],id1));id1=id3;two.pop();}
        }
        if (id1<=n) one.push(mp(-a[id1+n],id1+n));
        ans+=a[id1];vis[id1]=1;res[id1%n]++;
    }
    cout<<ans<<endl;
    for (int i=1;i<n;i++) cout<<res[i];cout<<res[0]<<endl;
}