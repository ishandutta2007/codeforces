#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        a[i][0]=a[0][i]=1;
    }
    for (int i=1;i<n;i++)
    {
        for (int j=1;j<n;j++)
            a[i][j]=a[i-1][j]+a[i][j-1];
    }
    cout<<a[n-1][n-1]<<endl;
}