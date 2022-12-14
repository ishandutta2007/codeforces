# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
int points[100000][2];
int main()
{   
    int tot=0;
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
    {
        if (i%2==0)
        {
            for (int x=1;x<=m;x++)
            {
                points[tot][0]=i;
                points[tot][1]=x;
                tot++;
            }
        }
        else
        {
            for (int x=m;x>=1;x--)
            {
                points[tot][0]=i;
                points[tot][1]=x;
                tot++;
            }
        }
    }
    int t=0;
    for (int i=0;i<k-1;i++)
    {
        cout<<2<<" "<<points[t][0]<<" "<<points[t][1]<<" "<<points[t+1][0]<<" "<<points[t+1][1]<<endl;
        t+=2;
    }
    cout<<tot-t<<" ";
    for (int i=t;i<tot;i++)
    {
        cout<<points[i][0]<<" "<<points[i][1]<<" ";
    }
    cout<<endl;
}