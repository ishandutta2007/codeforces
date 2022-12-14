#include<bits/stdc++.h>
using namespace std;
int d[2000000];
vector<int> leaf;
int id=-1;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i+1<n;i++)
    {
        int u,v;
        cin>>u>>v;
        d[u]++;
        d[v]++;
    }
    for (int i=1;i<=n;i++)
    {
        if (d[i]>2 && id!=-1)
        {
            cout<<"No"<<endl;
            return 0;
        }
        if (d[i]>2)
            id = i;
        if (d[i]==1)
            leaf.push_back(i);
    }
    if (id==-1)
    {
        for (int i=0;i<n;i++)
        {
            if (d[i]>1)
                id=i;
        }
    }
    if (n==2)
    {
        cout<<"Yes"<<endl;
        cout<<"1\n1 2\n";
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<leaf.size()<<endl;
    for (int i=0;i<leaf.size();i++)
        cout<<id<<' '<<leaf[i]<<endl;
}