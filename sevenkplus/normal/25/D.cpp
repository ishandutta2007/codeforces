#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1025
vector<pair<int,int> >p,q,s;
vector<int> a[N],b;
int n,f[N];bool v[N];
int fa(int x){if(f[x]==x)return x;else return f[x]=fa(f[x]);}
void ff(int x)
{
    v[x]=1;
    for(int i=0;i<a[x].size();i++)
    {
        if(!v[a[x][i]])ff(a[x][i]);
        if(a[x][i]<x)s.push_back(make_pair(a[x][i],x));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)if(!v[i])
    {
        b.push_back(i),s.clear(),ff(i);
        for(int j=0,x,y;j<s.size();j++)
            if(fa(x=s[j].first)!=fa(y=s[j].second))f[f[x]]=y;
            else p.push_back(s[j]);
    }
    for(int i=1;i<b.size();i++)q.push_back(make_pair(b[i-1],b[i]));
    printf("%d\n",(int)p.size());
    for(int i=0;i<p.size();i++)printf("%d %d %d %d\n",p[i].first,p[i].second,q[i].first,q[i].second);
    return 0;
}