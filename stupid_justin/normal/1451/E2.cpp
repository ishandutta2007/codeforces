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
const int mod=998244353;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
int ksm(int x,int y){int ret=1;while (y){if (y&1) ret=(ret*x)%mod;x=(x*x)%mod;y>>=1;}return ret;}

int n,q,sum,id1,id2;
int b[N];
int a[N];
int c[N];
int gb(int x,int i)
{
	//xi
	x>>=i;
	return x&1; 
}
/*
for (int i=0;i<=15;i++)
    {
        //i
        int tmp=1<<(i);
        for (int A=0;A<=1;A++)
            for (int B=0;B<=1;B++)
                for (int C=0;C<=1;C++)
                {
                    if ((A^B)==gb(a1,i)) if ((B^C)==gb(a2,i))
                    if ((B&A)==gb(a3,i)) if ((C&A)==gb(a4,i))
                    if ((B&C)==gb(a5,i))
                    {
                        a[1]|=(A<<i);
                        a[2]|=(B<<i);
                        a[3]|=(C<<i);
                        break;
                    }
                }
    }
*/
signed main()
{
	cin>>n;
	for (int i=2;i<=n;i++)
	{
		cout<<"XOR 1 "<<i<<endl;
		cin>>b[i];
		if (c[b[i]]) id1=c[b[i]],id2=i;//
		else  c[b[i]]=i;
	}
	if (id1)
	{
		//
		//b[id1]=b[id2]
		cout<<"AND "<<id1<<" "<<id2<<endl;cin>>b[n+1];
		a[id1]=b[n+1];a[1]=a[id1]^b[id1];
		for (int i=2;i<=n;i++) a[i]=a[1]^b[i]; 
	} else if (c[0])
	{
		//a[1]
		//a[c[0]]=a[1]
		cout<<"AND 1 "<<c[0]<<endl;cin>>a[1];
		for (int i=2;i<=n;i++) a[i]=a[1]^b[i]; 
	}else
	{
		//for (int i=2;i<=n;i++) printf("b[%lld]=%lld ",i,b[i]);cout<<endl;
		//for (int i=1;i<n;i++) printf("c[%lld]=%lld ",i,c[i]);cout<<endl;
		//
		//c[0]c[n-1]
		id1=c[n/2];id2=c[n/2-1];
		int a1,a2,a3,a4,a5;
		a1=b[id1];a2=b[id2];a5=0;
		cout<<"AND 1 "<<id1<<endl;cin>>a3;
		cout<<"AND 1 "<<id2<<endl;cin>>a4;
		//cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4<<" "<<a5<<endl;
		for (int i=0;i<=15;i++)
    	{
    	    //i
    	    for (int A=0;A<=1;A++)
    	    for (int B=0;B<=1;B++)
    	    for (int C=0;C<=1;C++)
    	    {
    	        if ((A^B)==gb(a1,i)) if ((A^C)==gb(a2,i))
    	        if ((B&A)==gb(a3,i)) if ((C&A)==gb(a4,i))
    	        if ((B&C)==gb(a5,i))
    	        {
    	            a[1]|=(A<<i);
                    a[id1]|=(B<<i);
                    a[id2]|=(C<<i);
    	            break;
    	        }
    	    }
    	}
        //printf("%lld %lld %lld\n",a[1],a[id1],a[id2]);
    	for (int i=2;i<=n;i++) a[i]=a[1]^b[i];
	}
	cout<<"! ";for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
}