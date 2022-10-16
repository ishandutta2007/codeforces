
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
#define ls (rt<<1)
#define rs (rt<<1|1)
using namespace std;
const int N=2e6+5;
const int maxn=5e6+5;
const int mod=998244353;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9' || ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y,int z){int ret=1;while (y){if  (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
inline int ksm(int x,int y){int ret=1;while (y){if  (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}
inline int INV(int x){return ksm(x,mod-2);}
int n,m,b[N],id[N],tot,d,cnt;
double tag[N],ans;//p
struct tree
{
	int x,h,l,r;
}T[N];
struct mogu
{
	int x,v;
}M[N];
int find(int x)
{
	int L=1,R=cnt,mid;
	while(L<=R)
    {
		mid=L+R>>1;
		if (id[mid]==x) return mid;
		id[mid]<x?L=mid+1:R=mid-1; 
	}
}
void build(int rt,int l,int r)
{
	tag[rt]=1,d++;
	if (l==r) return;
	int mid=l+r>>1;
	build(ls,l,mid);
    build(rs,mid+1,r); 
}
void update(int rt,int L,int R,int l,int r,double x)
{
//    printf("update(%lld,%lld,%lld,%lld,%lld,%lf)\n",rt,L,R,l,r,x);
	if (L>r || R<l) return;
	if (l<=L && R<=r)
    {tag[rt]*=x/100.0;return;}
	if (L==R) return;
	int mid=L+R>>1;
	update(ls,L,mid,l,r,x);
    update(rs,mid+1,R,l,r,x);
}
double query(int rt,int l,int r,int x)
{
//    printf("query(%lld,%lld,%lld,%lld)\n",rt,l,r,x);
	if (l==r) return tag[rt];
	int mid=l+r>>1;
	if (mid>=x) return query(ls,l,mid,x)*tag[rt];
	else return query(rs,mid+1,r,x)*tag[rt];
}
signed main()
{
	rd(n);rd(m);
	for (int i=1;i<=n;i++)
    {
		T[i].x=read(),T[i].h=read(),T[i].l=read(),T[i].r=read();
		b[++tot]=T[i].x-T[i].h,b[++tot]=T[i].x-1,b[++tot]=T[i].x+1,b[++tot]=T[i].x+T[i].h;
	}
	for (int i=1;i<=m;i++)
    {
		rd(M[i].x);
        rd(M[i].v);
		b[++tot]=M[i].x;
	}
	sort(b+1,b+1+tot);
	for (int i=1;i<=tot;i++) if (b[i]!=b[i+1]) id[++cnt]=b[i];
	build(1,1,cnt);

	for (int i=1;i<=n;i++)
    {
		int L=find(T[i].x-T[i].h);
        int midl=find(T[i].x-1);
        int midr=find(T[i].x+1);
        int R=find(T[i].x+T[i].h);
		update(1,1,cnt,L,midl,(double)100.0-T[i].l);
        update(1,1,cnt,midr,R,(double)100.0-T[i].r);
	}
//    for (int i=1;i<=10;i++) cout<<tag[i]<<" ";cout<<endl;
	for (int i=1;i<=m;i++)
    {
		int x=find(M[i].x);
		ans+=(double)query(1,1,cnt,x)*M[i].v;
	}
	printf("%.5lf\n",ans);
}