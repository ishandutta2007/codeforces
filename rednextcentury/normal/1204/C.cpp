#include<bits/stdc++.h>
using namespace std;
int dist[200][200];
int shortest[1000006];
int bk[1000006];
int a[1000006];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                dist[i][j]=1e5;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            char x;
            cin>>x;
            if (x=='1')
                dist[i][j]=x-'0';
        }
    }
    for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

    int m;
    cin>>m;
    shortest[0]=0;
    cin>>a[1];
    shortest[1]=1;
    for (int i=2;i<=m;i++)
    {
        cin>>a[i];
        shortest[i]=1e8;
        int len=0;
        for (int j=i-1;j>=1;j--)
        {
            len++;
            if (len>=n)break;
            if (shortest[j]+1<shortest[i] && dist[a[j]][a[i]]==len)
                shortest[i]=shortest[j]+1,bk[i]=j;
        }
    }
    vector<int> vec;
    int v=m;
    while(1)
    {
        vec.push_back(a[v]);
        v=bk[v];
        if (v==0)break;
    }
    reverse(vec.begin(),vec.end());
    cout<<shortest[m]<<endl;
    for (auto x:vec)cout<<x<<' ';


}