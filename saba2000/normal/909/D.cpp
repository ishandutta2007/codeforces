#include<bits/stdc++.h>
using namespace std;
int
main()
{
    vector<pair<int,char> > G;
    string a;
    cin>>a;
    a+='?';
    int k=0;
    for (int i=1; i<a.size(); i++)
    {
        if(a[i]!=a[i-1])
        {
           G.push_back({i-k,a[i-1]});
           k=i;
        }
    }
    int ans=0;
    while(G.size()>1)
    {
       for (int i=0; i<G.size(); i++)
       {
          // cout<<G[i].first<<" "<<G[i].second<<endl;
           if(i==0 || i==G.size()-1)
            G[i].first--;
           else
            G[i].first-=2;
       }
       vector<pair<int,char> > G1;
       int k=0;
       for (int i=0; i<G.size(); i++)
        {
            if(G[i].first<=0) continue;
            if(G1.size()==0) G1.push_back(G[i]); else
            if(G1.back().second==G[i].second) G1.back().first+=G[i].first;
            else G1.push_back(G[i]);
        }
        G=G1;
       ans++;
    }
    cout<<ans<<endl;
}