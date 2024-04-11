#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > X;
vector<pair<int,int> > Y;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        X.clear();Y.clear();
        int n;
        cin>>n;
        while(n--)
        {
            int x,y,L,D,R,U;
            cin>>x>>y>>L>>D>>R>>U;
            if (U && !D)
                Y.push_back({-1e9,y});
            if (!U && D)
                Y.push_back({y,1e9});
            if (!U && !D)
            Y.push_back({y,y});
            if (L && !R)
            X.push_back({-1e9,x});
            if (R&& !L)
            X.push_back({x,1e9});
            if (!R && !L)
            X.push_back({x,x});
        }
        int LX=-1e5,RX=1e5;
        int LY=-1e5,RY=1e5;
        for (auto p:X)
            LX=max(LX,p.first),RX=min(RX,p.second);

        for (auto p:Y)
            LY=max(LY,p.first),RY=min(RY,p.second);
        if (LX>RX || LY>RY)
            cout<<0<<endl;
        else
        {
            cout<<1<<' '<<LX<<' '<<RY<<endl;
        }
    }
}