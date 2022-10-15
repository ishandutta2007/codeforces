#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,cnt;
string A,B;
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
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
    cnt++;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>A;
        cin>>B;
        init(20);
        cnt=0;
        bool f=true;
        for(int i=0;i<n;i++)
        {
            if(A[i]!=B[i])
            {
                if(B[i]<A[i]) f=false;
                else unite(A[i]-'a',B[i]-'a'); 
            }
        }
        if(!f) puts("-1"); else printf("%d\n",cnt);
    }
    return 0;
}