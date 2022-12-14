#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int vis[51][51];
vector<pair<int,int> > num[10000];
int ret[100];
bool v[1001];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=n;i++)
    {
        vector<int> vec;
        for (int x=1;x<=n;x++)
        {
                if (++vis[i][a[x][i]]==2)
                    vec.push_back(a[x][i]);

                if (++vis[i][a[i][x]]==2)
                    vec.push_back(a[i][x]);
        }
        for (int j=0;j<vec.size();j++)
            num[vec[j]].push_back(make_pair(vis[i][vec[j]],i));
    }
    for (int i=1;i<=n;i++)
    {
        sort(num[i].begin(),num[i].end());
        for (int j=num[i].size()-1;j>=0;j--)
        {
          //  cout<<num[i][j].first<<" "<<num[i][j].second<<endl;
            if (!v[num[i][j].second])
            {
            ret[num[i][j].second]=i,v[num[i][j].second]=1;
            break;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if(ret[i]==0)ret[i]=n;
        cout<<ret[i]<<' ';
    }
    cout<<endl;
}