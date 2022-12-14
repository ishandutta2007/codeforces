#include<stdio.h>
# include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v;
set<pair<int,int> > s;
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n; i++)
    {
        int x;
        cin>>x;
        s.insert(make_pair(x,i));
    }
    if (n==1)
    {
        cout<<"0 0"<<endl;
        return 0;
    }
    for (int i=0;i<k;i++)
    {
        pair<int,int> mn;
        mn.first=s.begin()->first;
        mn.second=s.begin()->second;
        pair<int,int> mx=make_pair((--s.end())->first,(--s.end())->second);
        if (mn.first+1>=mx.first)
            break;
        mn.first++;
        mx.first--;
        v.push_back(make_pair(mx.second+1,mn.second+1));
        s.erase(s.begin());
        s.erase(--s.end());
        s.insert(mn);
        s.insert(mx);
    }
    pair<int,int> mn=*s.begin();
    pair<int,int> mx=*(--s.end());
    cout<<mx.first-mn.first<<' '<<v.size()<<endl;
    for (int i=0;i<v.size();i++)
        cout<<v[i].first<<' '<<v[i].second<<endl;

}