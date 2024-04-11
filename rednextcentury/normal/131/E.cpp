#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > d1[1000000];
vector<pair<int,int> > d2[1000000];
vector<pair<int,int> > r[1000000];
vector<pair<int,int> > c[1000000];
int ans[1000000];
int ret[9];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        r[x].push_back(make_pair(y,i));
        c[y].push_back(make_pair(x,i));
        d1[x-y+n].push_back(make_pair(x,i));
        d2[x+y].push_back(make_pair(x,i));
    }
    for (int i=0;i<n+n+1;i++)
    {
        sort(d1[i].begin(),d1[i].end());
        sort(d2[i].begin(),d2[i].end());
        sort(r[i].begin(),r[i].end());
        sort(c[i].begin(),c[i].end());
        for (int j=0;j<d1[i].size();j++)
        {
            if (j+1<d1[i].size())
                ans[d1[i][j].second]++;
            if (j!=0)
                ans[d1[i][j].second]++;
        }
        for (int j=0;j<d2[i].size();j++)
        {
            if (j+1<d2[i].size())
                ans[d2[i][j].second]++;
            if (j!=0)
                ans[d2[i][j].second]++;
        }
        for (int j=0;j<r[i].size();j++)
        {
            if (j+1<r[i].size())
                ans[r[i][j].second]++;
            if (j!=0)
                ans[r[i][j].second]++;
        }
        for (int j=0;j<c[i].size();j++)
        {
            if (j+1<c[i].size())
                ans[c[i][j].second]++;
            if (j!=0)
                ans[c[i][j].second]++;
        }
    }

    for (int i=0;i<m;i++)
        ret[ans[i]]++;
    for (int i=0;i<=8;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}