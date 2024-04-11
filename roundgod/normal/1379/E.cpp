#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int fa[MAXN];
bool is_bal(int n)
{
    int x=__builtin_popcount(n);
    return (n==((1<<x)-1));
}
bool check(int n,int k)
{
    if(n%2==0) return false;
    if(n==1&&k==0) return true;
    if(k>(n-3)/2) return false;
    if(k==0&&!is_bal(n)) return false;
    if(k==1&&is_bal(n)) return false;
    if(n==9&&k==2) return false;
    return true;
}
void build(int l,int r,int k)
{
    int n=r-l+1;
    if(n==1) return;
    if(k==0)
    {
        for(int i=2;i<=n;i++) fa[i+l-1]=i/2+l-1;
        return;
    }
    for(int i=1;i<=n-2;i++)
    {
        int x=is_bal(i)?0:1;
        x+=(max(i,n-1-i)>=2*min(i,n-1-i)?1:0);
        if(k>=x&&check(n-1-i,k-x))
        {
            fa[l+1]=l;
            build(l+1,l+i,is_bal(i)?0:1);
            fa[l+i+1]=l;
            build(l+i+1,r,k-x);
            return;
        }
    }
    assert(0);
}
int main()
{
    scanf("%d%d",&n,&k);
    if(!check(n,k)) {puts("NO"); return 0;}
    puts("YES");
    build(1,n,k);
    for(int i=1;i<=n;i++) printf("%d ",fa[i]);
    return 0;
}