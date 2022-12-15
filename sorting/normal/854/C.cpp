#include<iostream>
#include<queue>

using namespace std;

long long c[300002];
long long res[300002],result;

priority_queue<pair<long long,long long>> q;

int main ()
{
    long long n,k,i;
    pair<long long,long long>p;

    cin>>n>>k;

    for(i=1;i<=n;i++)cin>>c[i];

    for(i=1;i<=k;i++)
    {
        p.first=c[i];
        p.second=i;
        q.push(p);
    }

    for(i=k+1;i<=n;i++)
    {
        p.first=c[i];
        p.second=i;
        q.push(p);
        p=q.top();
        res[p.second]=i;
        result+=p.first*(i-p.second);
        q.pop();
    }

    for(i=n+1;i<=n+k;i++)
    {
        p=q.top();
        res[p.second]=i;
        result+=p.first*(i-p.second);
        q.pop();
    }

    cout<<result<<endl;

    for(i=1;i<n;i++)cout<<res[i]<<" ";
    cout<<res[i]<<endl;

    return 0;
}