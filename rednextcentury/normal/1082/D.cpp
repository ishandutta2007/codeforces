#include <bits/stdc++.h>
using namespace std;
vector<int> ones;
vector<pair<int,int> > rest;
vector<pair<int,int> > edges;
int a[10000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=(a[i]==1);
        if (a[i]==1)ones.push_back(i);
        else rest.push_back({a[i],i});
    }
    sort(rest.begin(),rest.end());
    reverse(rest.begin(),rest.end());
    while(ones.size()<2)
    {
        pair<int,int> p = rest.back();
        rest.pop_back();
        ones.push_back(p.second);
    }
    int s = ones.back();
    ones.pop_back();
    int e = ones.back();
    ones.pop_back();
    int last = s;
    for (int i=0;i<rest.size();i++)
    {
        rest[i].first--;
        edges.push_back({last,rest[i].second});
        if (i>0)rest[i-1].first--;
        last = rest[i].second;
    }
    if (rest.size()>0)rest[rest.size()-1].first--;
    edges.push_back({last,e});
    int ret = rest.size()+1;
    for (int i=0;i<rest.size();i++)
    {
        while(rest[i].first>0 && ones.size()>0)
        {
            edges.push_back({ones.back(),rest[i].second});
            rest[i].first--;
            ones.pop_back();
        }
    }
    if (ones.size()>0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES "<<ret<<endl<<edges.size()<<endl;
    for (auto x:edges)
        cout<<x.first<<' '<<x.second<<endl;

}