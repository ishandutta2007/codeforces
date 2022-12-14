# include <iostream>
# include <stdio.h>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
using namespace std;
int a[100][100];
bool sym(int x,int y)
{
    for (int i=0;i<y;i++)
    {
        for (int j=0;j<x/2;j++)
        {
            if (a[j][i]!=a[x-j-1][i])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int x,y;
    cin>>x>>y;
    for (int i=0;i<x;i++)
    {
        for (int j=0;j<y;j++)
        {
            cin>>a[i][j];
        }
    }
    while (true)
    {
        if (x%2!=0)
            break;
        if (sym(x,y))
            x=x/2;
        else
            break;
    }
    cout<<x<<endl;
}