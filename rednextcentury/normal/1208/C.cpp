#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int cur=0;
    for (int i=0;i<n;i+=4)
        for (int j=0;j<n;j+=4)
            for (int x=0;x<4;x++)
                for (int y=0;y<4;y++)
                    a[i+x][j+y]=cur++;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}