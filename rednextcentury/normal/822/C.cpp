#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll l[1000000], r[1000000], x[1000000];
multiset<int> mn[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,len;
    cin>>n>>len;
    vector<pair<pair<int,int>, int> > events;
    int m = 3e5;
    for (int i=1;i<=n;i++){
        cin>>l[i]>>r[i]>>x[i];
        mn[r[i]-l[i]+1].insert(x[i]);
        events.push_back({{l[i], 0},i});
        events.push_back({{r[i],1},i});
    }
    sort(events.begin(),events.end());
    ll ret=2e9+1;
    for (auto ev:events){
        int X = ev.first.first;        int typ = ev.first.second;
        int id = ev.second;
        if (typ==0){
            mn[r[id]-l[id]+1].erase(mn[r[id]-l[id]+1].find(x[id]));
        } else {
            int need = len - (r[id]-l[id]+1);
            if (need>=0){
                if (mn[need].empty())continue;
                ret=min(ret, x[id]+*mn[need].begin());
            }
        }
    }
    if (ret>2e9)ret=-1;
    cout<<ret<<endl;

}