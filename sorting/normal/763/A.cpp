#include<iostream>
#include<vector>

using namespace std;

vector<int> v[100001];
int c[100001];
vector<pair<int,int>> p;

int main ()
{
    int n,i,a,b,j;

    cin>>n;

    for(i=0;i<n-1;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(i=1;i<=n;i++)
        cin>>c[i];

    for(i=1;i<=n;i++)
    {
        for(j=0;j<v[i].size();j++)
        {
            if(c[i]!=c[v[i][j]])
            {
                p.push_back(make_pair(i,v[i][j]));
            }
        }
    }

    if(p.empty())
    {
        cout<<"YES"<<endl;
        cout<<"1"<<endl;
        return 0;
    }

    a=p[0].first;
    b=p[0].second;

    for(i=1;i<p.size();i++)
    {
        if(p[i].first!=a && p[i].second!=a)
            a=0;
        if(p[i].first!=b && p[i].second!=b)
            b=0;
    }

    if(a==0 && b==0)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        if(a!=0)
            cout<<a<<endl;
        else
            cout<<b<<endl;
    }

    return 0;
}