#include <bits/stdc++.h>
using namespace std;
int a[10000];
vector<int> ret[1000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
        int mn=1000000;
        for (int j=0;j<n;j++)
        {
            if (a[j]>0)
            mn=min(mn,a[j]);
        }
        for (int j=0;j<n;j++)
        {
            if (a[j]==mn)
            {
                a[j]=0;
                for (int x=0;x<mn;x++)
                    ret[j].push_back(1);
            }
            else if (a[j]>mn)
            {
                a[j]-=mn+1;
                for (int x=0;x<=mn;x++)
                    ret[j].push_back(1);
            }
        }
    for (int i=2;i<=k;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[j]>0)
            {
                a[j]--;
                    ret[j].push_back(i);
            }
        }
    }
    bool gg=0;
    for (int i=0;i<n;i++)
        if (a[i]>0)
            gg=1;
    if (!gg)
    {
        cout<<"YES"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<ret[i][0];
        for (int j=1;j<ret[i].size();j++)
            cout<<" "<<ret[i][j];
        cout<<endl;
    }
    }
    else
        cout<<"NO"<<endl;
}