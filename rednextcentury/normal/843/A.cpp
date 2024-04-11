#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
vector<vector<int> > vec;
bool vis[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i].first=x;
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            vector<int> v;
            int c=i;
            while(!vis[c])
            {
                v.push_back(c);
                vis[c]=1;
                c=a[c].second;
            }
            vec.push_back(v);
        }
    }
    cout<<vec.size()<<endl;
    for (int i=0;i<vec.size();i++)
    {
        cout<<vec[i].size();
        for (int j=0;j<vec[i].size();j++)
            cout<<' '<<vec[i][j];
        cout<<endl;
    }
}