//#pragma GCC optimize(3)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <unordered_map>
#include <map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
#define int unsigned long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
int a[20],l;
struct Node{
    int x,d;
}x;
std::queue<Node>q;
#define end {puts("-1");return 0;}
int cengyiceng[22];
inline int digit(int x,int pos)
{
    int q=cengyiceng[pos];
    return (x/q)%10;
}
inline int modi(int x,int pos,int y)
{
    int q=1,p=x;
    q=cengyiceng[pos];
    int qwq=digit(x,pos);
    p-=qwq*q;
    p+=y*q;
    return p;
}
int ok(int p)
{
    return (p==1||p==3||p==4||p==6||p==8||p==9);
}
gp_hash_table<int,bool> mp;
signed main()
{
    int n=read();
    cengyiceng[0]=1;
    for(int i=1;i<=20;i++)cengyiceng[i]=cengyiceng[i-1]*10;
    l=n;
    while(l)a[l%10]++,l/=10;
    if(a[0]>=2)goto ok;
    if(a[0]&&a[5])goto ok;
    if(a[5]&&a[2])goto ok;
    if(a[5]&&a[7])goto ok;
    end;
    ok:;
    int pos=1,deg=0;
    while(pos*10<=n)pos*=10,deg++;
    for(int i=0;i<=deg;i++)
    {
    	int p=digit(n,i);
    	if(ok(p))n=modi(n,i,1);
    	else if(p==2)n=modi(n,i,7);
    	if((a[5]==0)&&(p==2||p==7))n=modi(n,i,1);
    //	printf("%llu\n",p);
	}
	//printf("%llu\n",n);
	//700777111111222222
    x.x=n,x.d=0;
    q.push(x);
    mp[n+171487]=1;
    while(!q.empty())
    {
        x=q.front();q.pop();
        int u=x.x,d=x.d;
        if(u%25==0){printf("%llu\n",d);return 0;}
        for(int i=1;i<=deg;i++)
        {
            int hi=digit(u,i),lo=digit(u,i-1);
            if(ok(hi)&&ok(lo))continue;
            if(hi==lo)continue;
            int v=u;
            v=modi(v,i,lo);
            v=modi(v,i-1,hi);
            if(v>=pos&&mp[v+171487]==0)mp[v+171487]=1,q.push((Node){v,d+1});
        }
    }
    end;
}