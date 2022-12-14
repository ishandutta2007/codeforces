#include<bits/stdc++.h>
using namespace std;
int a[101][10001];
int sum[10001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;i++)
    {
        a[i][0]=s[i]-'0';
        sum[0]+=a[i][0];
        int x,y;
        cin>>y>>x;
        for (int j=1;j<=10000;j++)
        {
            if (j<x || (j-x)%y)a[i][j]=a[i][j-1];
            else a[i][j]=1-a[i][j-1];
            sum[j]+=a[i][j];
        }
    }
    int ret=0;
    for (int i=0;i<=10000;i++)ret=max(ret,sum[i]);
    cout<<ret<<endl;
}