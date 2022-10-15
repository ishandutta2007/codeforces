#include<bits/stdc++.h>
#define MAXN 150005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int T,n,k,a[MAXN];
int p2[MAXN];
vector<int> id;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int solve2(vector<int> &l,vector<int> &r,int b)
{
    if(!l.size()) p2[(int)r.size()];
    if(!r.size()) return p2[(int)l.size()];
    /*printf("b=%d ",b);
    for(auto x:l) printf("%d ",a[x]);
    puts("");
    for(auto x:r) printf("%d ",a[x]);
    puts("");*/
    if(b<0) 
    {
        int ret=p2[(int)l.size()+(int)r.size()];
        return ret;
    }
    vector<int> lzero,lone,rzero,rone;
    for(auto x:l) if(a[x]&(1<<b)) lone.push_back(x); else lzero.push_back(x);
    for(auto x:r) if(a[x]&(1<<b)) rone.push_back(x); else rzero.push_back(x);
    if(k&(1<<b))
    {
        return 1LL*solve2(lzero,rone,b-1)*solve2(lone,rzero,b-1)%MOD;
    }
    else
    {
        int ret=p2[(int)l.size()];
        add(ret,p2[(int)r.size()]);
        if(lzero.size()&&rzero.size()) 
        {
            add(ret,solve2(lzero,rzero,b-1));
            dec(ret,p2[(int)lzero.size()]); dec(ret,p2[(int)rzero.size()]);
            add(ret,1);
        }
        if(lone.size()&&rone.size()) 
        {
            add(ret,solve2(lone,rone,b-1));
            dec(ret,p2[(int)lone.size()]); dec(ret,p2[(int)rone.size()]);
            add(ret,1);
        }
        dec(ret,1);
        return ret;
    }
}
int solve(vector<int> &id,int b)
{
    if(!id.size()) return 0;
    if(b<0) 
    {
        int ret=p2[(int)id.size()];
        dec(ret,1);
        return ret;
    }
    vector<int> zero,one;
    for(auto x:id) if(a[x]&(1<<b)) one.push_back(x); else zero.push_back(x);
    if(k&(1<<b))
    {
        int ret=solve2(zero,one,b-1);
        dec(ret,1);
        return ret;
    }
    else
    {
        int ret=solve(zero,b-1);
        add(ret,solve(one,b-1));
        return ret;
    }
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=150000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) id.push_back(i);
    printf("%d\n",solve(id,30));
    return 0;
}