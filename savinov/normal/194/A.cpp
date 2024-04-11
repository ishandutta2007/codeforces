#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int a[51][257];
    for (int i=0;i<=k;i++)
    {
        a[0][i]=1000;
    }
    a[0][0]=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=k;j++) a[i+1][j]=1000;
        for (int j=0;j<=k;j++)
        {
            a[i+1][j+2]=min(a[i+1][j+2],a[i][j]+1);
            for (int p=3;p<=5;p++)
            {
                a[i+1][j+p]=min(a[i+1][j+p],a[i][j]);
            }
        }
    }
    cout << a[n][k];
    return 0;
}