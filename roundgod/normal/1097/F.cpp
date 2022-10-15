#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
int prime[MAXN],miu[MAXN];
bool is_prime[MAXN];
void genmiu(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    memset(miu,0,sizeof(miu));
    is_prime[0]=is_prime[1]=true;
    miu[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; miu[i]=-1;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[i*prime[j]]=false;
            miu[i*prime[j]]=i%prime[j]?-miu[i]:0;
            if(i%prime[j]==0) break;
        }
    }
}
bitset<7000> mu[7005];
bitset<7000> a[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    genmiu(7000);
    for(int i=1;i<=7000;i++) 
    {
        for(int j=i;j<=7000;j++)
            if(j%i==0&&miu[j/i]!=0) mu[i].set(j-1);
    }
    for(int i=0;i<q;i++)
    {
        int type,x,y,z,v;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&x,&v);
            a[x].reset();
            for(int j=1;j*j<=v;j++) 
            {
                if(v%j) continue;
                a[x].set(j-1);
                a[x].set(v/j-1);
            } 
        }
        else if(type==2)
        {
            scanf("%d%d%d",&x,&y,&z);
            a[x]=a[y]^a[z];
        }
        else if(type==3)
        {
            scanf("%d%d%d",&x,&y,&z);
            a[x]=a[y]&a[z];
        }
        else 
        {
            scanf("%d%d",&x,&v);
            bitset<7000> nb;
            nb=a[x]&mu[v];
            int ans=nb.count()%2;
            printf("%d",ans);
        }
    }
    return 0;
}