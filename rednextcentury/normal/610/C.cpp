#include <bits/stdc++.h>
using namespace std;
bool a[10][600][600];
int sz[10]={1,2,4,8,16,32,64,128,256,512};
void sol()
{
    a[0][0][0]=1;
    for (int k=1;k<=9;k++)
    {
        int n=sz[k-1];
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                bool x = a[k-1][i][j];
                a[k][i][j]=x;
                a[k][i][j+n]=!a[k-1][i][n-j-1];
                a[k][i+n][j]=a[k-1][i][j];
                a[k][i+n][j+n]=a[k-1][i][n-j-1];
            }
        }
    }
}
int main()
{
    sol();
    int k;
    cin>>k;
    for (int i=0;i<sz[k];i++)
    {
        for (int j=0;j<sz[k];j++)
        {
            if (a[k][i][j]==1)
                cout<<'+';
            else
                cout<<'*';
        }
        cout<<endl;
    }
}