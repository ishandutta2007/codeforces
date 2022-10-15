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
P a[MAXN];
bool used[MAXN];
int p[MAXN],r[MAXN],num[MAXN];
multiset<int> s;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        num[i]=1;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y])
    {
        s.erase(s.find(num[x]));
        s.erase(s.find(num[y]));
        p[x]=y;
        num[y]+=num[x];
        s.insert(num[y]);
    }
    else
    {
        s.erase(s.find(num[x]));
        s.erase(s.find(num[y]));
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
        num[x]+=num[y];
        s.insert(num[x]);
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].F);
        a[i].S=i+1;
    }
    sort(a,a+n);
    init(n);
    int ans=0,t=0;
    for(int i=0;i<n;i++)
    {
        used[a[i].S]=true;
        s.insert(1);
        if(a[i].S!=1&&used[a[i].S-1]) unite(a[i].S,a[i].S-1);
        if(a[i].S!=n&&used[a[i].S+1]) unite(a[i].S,a[i].S+1);
        multiset<int>::iterator it;
        if((*s.begin())!=*(s.rbegin())) continue;
        if(s.size()>ans)
        {
            ans=s.size();
            t=a[i].F+1;
        }
    }
    printf("%d\n",t);
    return 0;
}