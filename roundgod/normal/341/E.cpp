#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
int s;
vector<int> v;
vector<P> ans;
void go(int x,int y)
{
    if(a[x]>=a[y])
    {
        a[x]-=a[y];
        a[y]=2*a[y];
        ans.push_back(P(y,x));
    }
    else
    {
        a[y]-=a[x];
        a[x]=2*a[x];
        ans.push_back(P(x,y));
    }
}
void reduce(int x,int y,int z)
{
    if(a[x]>a[y]) swap(x,y); 
    if(a[x]>a[z]) swap(x,z);
    if(a[y]>a[z]) swap(y,z);
    int num=a[y]/a[x];
    for(int i=0;i<20;i++)
    {
        if((1<<i)>num) break;
        if(num&(1<<i)) go(x,y);
        else go(x,z);
    }
}
void die()
{
    puts("-1");
    exit(0);
}
void print()
{
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    exit(0);
}
void check()
{
    v.clear();
    for(int i=1;i<=n;i++)
    {
        if(a[i]) v.push_back(i);
    }
    if(v.size()==2) print();
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    check();
    if(v.size()<2) die();
    while(v.size()>=3)
    {
        int x=v.back(); v.pop_back();
        int y=v.back(); v.pop_back();
        int z=v.back(); v.pop_back();
        while(a[x]&&a[y]&&a[z]) reduce(x,y,z);
        check();
    }
    return 0;
}