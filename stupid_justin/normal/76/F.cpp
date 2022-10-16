
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
const int M=1e5+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x7f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}

struct SJ
{
    int T,X;
    int V1,V2;
}A[M];
int c[M],b[M];
bool cmp(SJ P,SJ Q){return P.V2==Q.V2?P.V1<Q.V1:P.V2<Q.V2;}
int N,v,m;

int stk[M],top;
int find(int l,int r,int x)
{
    int ret=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(stk[mid]>x) ret=mid,r=mid-1;
        else l=mid+1;
    }
    return ret;
}
void work(int a[],int n)
{
    int res=0;
    stk[0]=-inf;stk[1]=inf;top=1;
    for (int i=1;i<=n;i++)
    {
        res=max(res,top);
        int p=find(0,top,a[i]);
        if(stk[p]>a[i]) stk[p]=a[i];
        if(p>=top) stk[++top]=inf;
    }
    res=max(res,top);
    cout<<res-1<<" ";
}
signed main()
{
    rd(N);for(int i=1;i<=N;i++){rd(A[i].X);rd(A[i].T);}rd(v);
    for (int i=1;i<=N;i++) {A[i].V1=A[i].X+A[i].T*v;A[i].V2=-A[i].X+A[i].T*v;}
    sort(A+1,A+N+1,cmp);
    for (int i=1;i<=N;i++) {if (A[i].V1>=0 && A[i].V2>=0) b[++m]=A[i].V1;}
    for (int i=1;i<=N;i++) c[i]=A[i].V1;
    work(b,m);work(c,N);
}