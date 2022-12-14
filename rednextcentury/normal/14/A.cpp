# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
char a[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    int mnx=1000,mny=1000,mxx=0,mxy=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (a[i][j]=='*')
                mnx=min(mnx,i),mny=min(mny,j),mxx=max(mxx,i),mxy=max(mxy,j);
        }
    }
    for (int i=mnx;i<=mxx;i++)
    {
        for (int j=mny;j<=mxy;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}