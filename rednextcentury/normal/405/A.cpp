# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <ios>
# include <vector>
# include <map>
using namespace std;
int a[100][100];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        for (int j=0;j<x;j++)
        {
            a[i][j]=1;
        }
    }
    for (int i=n-2;i>=0;i--)
    {
       for (int x=0;x<100;x++)
       {
            if (a[i][x]==0)
                break;
            else
            {
                a[i][x]=0;
                bool p=0;
                for (int j=i;j<n-1;j++)
                {
                    if (a[j+1][x]==1)
                    {
                        a[j][x]=1;
                        p=1;
                    }
                }
                if (p==0)
                    a[n-1][x]=1;
            }
       }
    }
    for (int i=0;i<n;i++)
    {
        int x=0;
        for (int j=0;j<100;j++)
        {
            if (a[i][j]==0)
                break;
            x++;
        }
        cout<<x<<" ";
    }
    cout<<endl;
}