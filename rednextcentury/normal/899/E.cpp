#include <bits/stdc++.h>
using namespace std;
multiset<pair<int,pair<int,int> > > G;
multiset<pair<int,int> > S;
int main()
{
    int n;
    cin>>n;
    int last = -1;
    int num = 0;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x!=last)
        {
            if (last!=-1)
                G.insert({i-1,{last,num}}),S.insert({-num,i-1});
            last = x;
            num=1;
        }
        else
            num++;
    }
    if (num>0)
        G.insert({n-1,{last,num}}),S.insert({-num,n-1});
    num=0;
    while(!S.empty())
    {
        pair<int,int> p = *(S.begin());
        S.erase(S.begin());
        multiset<pair<int,pair<int,int> > >::iterator it = G.lower_bound({p.second,{-1,-1}});
        num++;
        multiset<pair<int,pair<int,int> > >::iterator it2 = it;
        if (it2==G.begin() || ++it2==G.end())
        {
            G.erase(it);
            continue;
        }
        pair<int,pair<int,int> > l = *(--it);
        ++it;
        pair<int,pair<int,int> > r = *(++it);
        --it;
        G.erase(it);
        if (l.second.first == r.second.first)
        {
            S.erase(S.find({-l.second.second,l.first}));
            S.erase(S.find({-r.second.second,r.first}));
            G.erase(G.find(l));
            G.erase(G.find(r));
            r.second.second+=l.second.second;
            G.insert(r);
            S.insert({-r.second.second,r.first});
        }
    }
    cout<<num<<endl;
}