#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXN];
bool is_prime[MAXN];
bool used[MAXN];
bool certified[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll get_pow(int a,int i)
{
    ll s=1;
    for(int j=0;j<i;j++) s*=a;
    return s;
}
vector<int> fact;
int count_multiple(int x)
{
    int cnt=0;
    for(int i=x;i<=n;i+=x) if(!used[i]) cnt++;
    return cnt;
}
void del_multiple(int x)
{
    for(int i=x;i<=n;i+=x) used[i]=true;
}
int query(int x)
{
    printf("A %d\n",x);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    return y;
}
void certify(int x)
{
    if(certified[x]) return;
    certified[x]=true;
    int cnt=1;
    ll now=x;
    while(1LL*now*x<=n) {cnt++; now*=x;}
    int l=1,r=cnt+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        assert(get_pow(x,mid)<=n);
        if(query(get_pow(x,mid))) l=mid; else r=mid;
    }
    fact.push_back(get_pow(x,l));
}
void query_and_del(int x)
{
    int cnt=count_multiple(x);
    printf("B %d\n",x);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    if(cnt!=y) certify(x);
    del_multiple(x);
}
void check(int l,int r)
{
    for(int i=l;i<=r;i++) if(query(prime[i])) certify(prime[i]);
}
void answer(int x)
{
    printf("C %d\n",x);
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    int p=sieve(n);
    for(int i=1;i<=n;i++) used[i]=false,certified[i]=false;
    bool f=true;
    int last=0;
    for(int i=0;i<p;i++)
    {
        query_and_del(prime[i]);
        if(i%100==99||i==p-1)
        {
            int cnt=count_multiple(1);
            if(f&&(query(1)!=cnt)) 
            {
                check(last,i);
                f=false;
            }
            last=i+1;
        }
    }
    int ans=1;
    for(auto x:fact) ans*=x;
    answer(ans);
    return 0;
}