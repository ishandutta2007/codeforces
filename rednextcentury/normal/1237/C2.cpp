#include <bits/stdc++.h>
using namespace std;
#define ll long long
int x[1000000];
int y[1000000];
int z[1000000];
#define X first.first
#define Y first.second
#define Z second.first
#define id second.second
set<pair<pair<int,int>,pair<int,int> > > s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>x[i]>>y[i]>>z[i],s.insert({{x[i],y[i]},{z[i],i}});
    vector<pair<int,int> > ret;
    while(s.size()>=2) {
        auto a = *s.begin();
        s.erase(s.begin());
        auto b = *s.begin();

        auto c = s.lower_bound({{b.X,a.Y},{-1e9,-1e9}});
        if (c==s.end())c--;
        else if ((*c).X != b.X)c--;
        auto d = s.lower_bound({{b.X,(*c).Y},{a.Z,-1e9}});
        if (d == s.end())d--;
        else if ((*d).Y != (*c).Y)
            d--;
        auto e = *d;
        s.erase(d);
        ret.push_back({a.id,e.id});
    }
    for (auto x:ret)cout<<x.first+1<<' '<<x.second+1<<endl;
}