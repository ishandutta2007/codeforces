#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int ret=0;
    for (int i=1;i+1<n;i++)
    {
        for (int j=1;j+1<n;j++)
        {
            if (a[i][j]=='X' && a[i+1][j+1]=='X' && a[i-1][j-1]=='X' && a[i-1][j+1]=='X' && a[i+1][j-1]=='X')
                ret++;
        }
    }
    cout<<ret<<endl;
}