#include<bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > a[1000000];
set<pair<int,int> > s;
set<pair<int,int> > ret;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int ans=-1;
    for (int i=0;i<n;i++)
        scanf("%d%d",&a[i].first,&a[i].second.first),a[i].second.second=i+1;
    sort(a,a+n);
    for (int i=0;i<n;i++)
    {
        if (s.size()<k)
            s.insert(make_pair(a[i].second.first,a[i].second.second));
        else if (s.size()==k)
        {
            if (a[i].second.first > (*s.begin()).first)
                s.erase(s.begin()),s.insert(make_pair(a[i].second.first,a[i].second.second));
        }
        int cur=(*(s.begin())).first - a[i].first + 1;
        cur=max(cur,0);
        if (cur>ans && s.size()==k)
        {
            ans=cur;
        }
    }
    s.clear();
    for (int i=0;i<n;i++)
    {
        if (s.size()<k)
            s.insert(make_pair(a[i].second.first,a[i].second.second));
        else if (s.size()==k)
        {
            if (a[i].second.first > (*s.begin()).first)
                s.erase(s.begin()),s.insert(make_pair(a[i].second.first,a[i].second.second));
        }
        int cur=(*(s.begin())).first - a[i].first + 1;
        cur=max(cur,0);
        if (cur==ans && s.size()==k)
        {
            ret=s;
            break;
        }
    }
    cout<<ans<<endl;
    while(ret.size())
    {
        cout<<(*ret.begin()).second<<' ';
        ret.erase(ret.begin());
    }
    cout<<endl;
}