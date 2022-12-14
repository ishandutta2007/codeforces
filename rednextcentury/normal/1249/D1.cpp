#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l[1000000];
int r[1000000];
vector<int> add[1000000];
vector<int> rem[1000000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    set<pair<int,int> > s;
    for (int i=1;i<=n;i++) {
        scanf("%d%d",&l[i],&r[i]);
        add[l[i]].push_back(i);
        rem[r[i]+1].push_back(i);
    }
    int m=200000;
    vector<int> del;
    for (int i=1;i<=m;i++)
    {
        for (auto x:add[i])s.insert({-r[x],x});
        for (auto x:rem[i])if (s.count({-r[x],x})) s.erase({-r[x],x});
        while(s.size()>k) {
            auto p = *s.begin();
            s.erase(s.begin());
            del.push_back(p.second);
        }
    }
    printf("%d\n",(int)del.size());
    for (auto x:del)printf("%d ",x);

}