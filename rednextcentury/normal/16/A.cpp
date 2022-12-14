# include <iostream>
# include <stdio.h>
# include <algorithm>
# include <map>
using namespace std;
char a[101][101];
int main()
{
    int n,m;
    cin>>n>>m;
    bool p=1;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if ((i>0 && a[i][j]==a[i-1][j]) || (j>0 && a[i][j]!=a[i][j-1])) p=0;
        }
    }
    cout<< (p?"YES":"NO")<<endl;
}