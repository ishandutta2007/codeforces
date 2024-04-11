#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int> > a;
vector<vector<int> > best;
int ret[1000000];
int main()
{
    int n,m;
    cin>>n>>m;
    a.resize(n,vector<int>(m));
    best.resize(n,vector<int>(m));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=n-1;i>=0;i--)
    {
        for (int j=0;j<m;j++)
        {
            int after = 0;
            if (i+1<n && a[i+1][j]>=a[i][j])
                after=best[i+1][j];
            best[i][j]=after+1;
            ret[i]=max(ret[i],best[i][j]);
        }
    }
    int k;
    cin>>k;
    while(k--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        if (ret[l]>(r-l))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}