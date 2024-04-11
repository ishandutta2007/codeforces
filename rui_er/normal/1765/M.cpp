// LUOGU_RID: 96020166
// ubsan: undefined
// accoders
#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx")
#pragma comment(linker,"/STACK:102400000,102400000")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(s)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define N 105005
#define MAX 2005
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=998244353,inf=1e18;
inline void read(ll &ret)
{
	ret=0;char c=getchar();bool pd=false;
	while(!isdigit(c)){pd|=c=='-';c=getchar();}
	while(isdigit(c)){ret=(ret<<1)+(ret<<3)+(c&15);c=getchar();}
	ret=pd?-ret:ret;
	return;
}
ll t,n;
signed main()
{
	read(t);
	while(t--)
	{
		read(n);
		if(!(n&1))
		{
			printf("%lld %lld\n",n/2,n/2);
		}
		else
		{
			ll ans=inf;
			for(int i=1;i*i<=n;i++)
			{
				if(!(n%i))
				{
					ll k=n/i-1;
					ans=min(ans,k*i);
					if(i==1)
						continue;
					ll tmp=n/i;
					k=n/tmp-1;
					ans=min(ans,k*tmp);
				}
			}
			for(int i=1;i*i<=n;i++)
			{
				if(!(n%i))
				{
					ll k=n/i-1;
					if(k*i==ans)
					{
						printf("%d %lld\n",i,k*i);
						break;
					}
					if(i==1)
						continue;
					ll tmp=n/i;
					k=n/tmp-1;
					if(k*tmp==ans)
					{
						printf("%d %lld\n",tmp,k*tmp);
						break;
					}
				}
			}
		}
	}
	exit(0); 
}