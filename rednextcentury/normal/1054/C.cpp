#include <bits/stdc++.h>
using namespace std;
int l[1000000];
int r[1000000];
vector<pair<int,int> > vec[1000000];
int ret[10000];
int tot=0;
void addAfter(int x,int y)
{
    for (int i=tot;i>x;i--)
        swap(ret[i],ret[i-1]);
    ret[x]=y;
    tot++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int curMex=0;
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>l[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>r[i];
        vec[l[i]+r[i]].push_back(make_pair(l[i],i));
    }
    for (int i=0;i<n;i++)
    {
        if (i>tot)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        for (int j=0;j<vec[i].size();j++)
        {
            if (vec[i][j].first>tot)
            {
                cout<<"NO"<<endl;
                return 0;
            }
            ret[vec[i][j].second]=n-i;
        }
        tot+=vec[i].size();
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<i;j++)
            if (ret[j]>ret[i])l[i]--;
        for (int j=n;j>i;j--)
            if (ret[j]>ret[i])r[i]--;
        if (l[i]!=0 || r[i]!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
    {
        cout<<ret[i]<<' ';
    }
    cout<<endl;
}