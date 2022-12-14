#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j]==1)continue;
            if (i==j && k)
                a[i][j]=1,k--;
            else if (i!=j && k>1)
                a[i][j]=a[j][i]=1,k-=2;
        }
    }
    if (k){
        cout<<-1<<endl;
        return 0;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
}