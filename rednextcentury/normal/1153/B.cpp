#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int top[1001][1001];
int LL[1001];
int RR[1001];
int main()
{
    int n,m,h;
    cin>>n>>m>>h;
    for (int i=0;i<m;i++)
        cin>>LL[i];
    for (int i=0;i<n;i++)
        cin>>RR[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>top[i][j];
    for (int j=0;j<m;j++)
    {
        for (int i=0;i<n;i++)
        {
            if (top[i][j]==0)continue;
            a[i][j]=min(LL[j],RR[i]);
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}