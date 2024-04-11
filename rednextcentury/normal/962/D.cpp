#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    set<pair<long long,long long> > s;
    set<pair<long long,long long> > a;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s.insert({x,i});
        a.insert({i,x});
    }
    while(s.size()>=2)
    {
        auto p = *s.begin(); s.erase(s.begin());
        auto q = *s.begin();
        if (p.first!=q.first)continue;
        s.erase(s.begin());
        a.erase({p.second,p.first});
        a.erase({q.second,q.first});
        a.insert({q.second,q.first*2});
        s.insert({q.first*2,q.second});
    }
    cout<<a.size()<<endl;
    for (auto p:a)
        cout<<p.second<<' ';
}