#include <bits/stdc++.h>
using namespace std;
int num[1000000];
int tot = 0;
set<pair<int,int> > s;
int mx = 0;
multiset<int> S;
int Add(int x)
{
    pair<int,int> p = *(--s.lower_bound(make_pair(x,2000000000)));
    s.erase(s.find(p));
    assert(p.first<=x && p.second>=x);
    S.erase(S.find(num[p.second-p.first+1]));
    num[p.second-p.first+1]--;
    S.insert(num[p.second-p.first+1]);
    pair<int,int> p1 = make_pair(p.first, x-1);
    pair<int,int> p2 = make_pair(x+1,p.second);
    if (p1.second>=p1.first)
        s.insert(p1);
    if (p2.second>=p2.first)
        s.insert(p2);
    bool ok=0;
    if (p1.second>=p1.first){
        S.erase(S.find(num[p1.second-p1.first+1]));
        if (++num[p1.second-p1.first+1]==s.size())
            ok=1;
        S.insert(num[p1.second-p1.first+1]);
    }
    if (p2.second>=p2.first){
        S.erase(S.find(num[p2.second-p2.first+1]));
        if (++num[p2.second-p2.first+1]==s.size())
            ok=1;
        S.insert(num[p2.second-p2.first+1]);
    }
    if (S.find((int)s.size())!=S.end())
        ok=1;
    if (ok)
        return s.size();
    return 0;
}
pair<int,int> a[1000000];
bool cmp(pair<int,int> x,pair<int,int> y)
{
    return x.first>y.first;
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i]=make_pair(x,i);
    }
    num[n]=1;
    s.insert(make_pair(0,n-1));
    S.insert(1);
    for (int i=1;i<n;i++)
        S.insert(0);
    sort(a,a+n,cmp);
    int best=0;
    int ret=-1;
    for (int i=0;i<n;i++)
    {
        int op=Add(a[i].second);
        if (op>best)
        {
            best = op;
            ret = a[i+1].first+1;
        }
        else if (op==best)
            ret = a[i+1].first+1;
    }
    if (n==1)
        cout<<a[0].first+1<<endl;
    else if (ret==-1)
        cout<<a[n-1].first<<endl;
    else
        cout<<ret<<endl;
}