#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<pair<int,pair<int,int> > > s;
vector<pair<int,int> > E;
int SS[1000000];
int DD[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        int d,S;
        cin>>d>>S;
        SS[i]=S;
        DD[i]=d;
        s.insert({d, {S, i}});
    }
    while(!s.empty()){
        auto p = *s.begin();
        s.erase(s.begin());
        int d = p.first;
        int v = p.second.second;
        int S = p.second.first;
        if (d==0)continue;
        else if (d==1){
            E.push_back({v,S});
            s.erase({DD[S],{SS[S],S}});
            SS[S]^=v;
            DD[S]--;
            s.insert({DD[S], {SS[S],S}});
        } else assert(0);
    }
    cout<<E.size()<<endl;
    for (auto e:E)cout<<e.first<<' '<<e.second<<endl;
}