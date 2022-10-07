#include<bits/stdc++.h>
using namespace std;
int n;
int g[100009],x[100009],t[100009],w,h;
int P[100009];
vector<pair<int,int> > vx[200009],vy[200009];
main()
{
    cin>>n>>w>>h;
    for (int i=0; i<n; i++)
    {
        cin>>g[i]>>x[i]>>t[i];
        if(g[i]==1)
        vx[x[i]-t[i]+100000].push_back({x[i],i});
        else vy[x[i]-t[i]+100000].push_back({x[i],i});
    }
    for (int i=0; i<2*1e5; i++)
    {
        sort(vx[i].begin(),vx[i].end());
        sort(vy[i].begin(),vy[i].end());
        for (int j=0; j<vx[i].size(); j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(vy[i].size()>=vx[i].size()-j)
                P[vx[i][j].second]=vy[i][vx[i].size()-j-1].second;
            else P[vx[i][j].second]=vx[i][j+vy[i].size()].second;
        }
    }
      for (int i=0; i<2*1e5; i++)
    {
        for (int j=0; j<vy[i].size(); j++)
        {//vx[i].size()-j-2
        // vy[i].size()
        //cout<<i<<" "<<j<<endl;
            if(vx[i].size()>=vy[i].size()-j)
                P[vy[i][j].second]=vx[i][vy[i].size()-j-1].second;
            else P[vy[i][j].second]=vy[i][j+vx[i].size()].second;
        }

    }
    for (int i=0; i<n; i++)
    {
        if(g[P[i]]==1)
            cout<<x[P[i]]<<" "<<h<<endl;
        else
            cout<<w<<" "<<x[P[i]]<<endl;
    }

}//x,t  y,w
//y-w=x-t