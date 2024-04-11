#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int p[200001],a[200001],b[200001];

bool boo[200001];

struct cmp
{
    bool operator()(const pair<int,int> w1,const pair<int,int> w2)
    {
        return w1.first>w2.first;
    }
};

priority_queue <pair<int,int>,vector<pair<int,int> >,cmp> q[3];

int main ()
{
    ios::sync_with_stdio(false);

    int n,i,m,x;
    pair<int,int> p1;

    cin>>n;

    for(i=0;i<n;i++)cin>>p[i];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];

    for(i=0;i<n;i++)
    {
        if(a[i]!=b[i])
        {
            p1.first=p[i];
            p1.second=i;
            q[a[i]-1].push(p1);
            q[b[i]-1].push(p1);
        }
        else
        {
            p1.first=p[i];
            p1.second=i;
            q[a[i]-1].push(p1);
        }
    }

    cin>>m;

    for(i=0;i<m-1;i++)
    {
        cin>>x;
        x--;

        while(!q[x].empty() && boo[q[x].top().second]==1)
        {
            //cout<<q[x].top()<<" ";
            q[x].pop();
        }
        if(!q[x].empty())
        {
            cout<<q[x].top().first<<" ";
            boo[q[x].top().second]=1;
            q[x].pop();
        }
        else cout<<"-1 ";

    }

    cin>>x;
    x--;

    while(!q[x].empty() && boo[q[x].top().second]==1)
    {
        //cout<<q[x].top()<<" ";
        q[x].pop();
    }
    if(!q[x].empty())
    {
        cout<<q[x].top().first<<endl;
        boo[q[x].top().second]=1;
        q[x].pop();
    }
    else cout<<"-1"<<endl;

    return 0;
}