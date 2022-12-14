#include<bits/stdc++.h>
using namespace std;

long long Get(long long n,long long x)
{
    long long ret=0;
    while(n%x)ret+=n/x,n--;
    ret+=n/x,n--;
    if (n<0)return ret;
    long long cur = n/x;
    return ret+(cur*(cur+1)/2) * x;
}
long long dist[430000];
int n;
bool vis[1000000];
int main()
{
    long long m,A,B;
    cin>>m>>A>>B;
    n = (A+B)*2;
    n=min(0LL+n,m);
    for (int i=1;i<=n;i++)
        dist[i]=m+1;
    priority_queue<pair<long long,int> > q;
    q.push({0,0});
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        if (vis[p.second])continue;
        vis[p.second]=1;
        long long d = -p.first;
        // +A
        int len = max(p.second+A,d);
        if (p.second+A<=n && len<dist[p.second+A])
        {
            dist[p.second+A]=len;
            q.push({-len,p.second+A});
        }
        // -B
        len = max(p.second-B,d);
        if (p.second-B>=0 && len<dist[p.second-B])
        {
            dist[p.second-B]=len;
            q.push({-len,p.second-B});
        }
    }
    long long ret=0;
    for (int i=0;i<=n;i++)
    {
        if (dist[i]<=n)
        {
            ret+=(n-dist[i]+1);
        }
    }
    long long x = __gcd(A,B);
    if (m>n)
        ret+=Get(m,x)-Get(n,x)+m-n;
    cout<<ret<<endl;
}