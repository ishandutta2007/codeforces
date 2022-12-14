#include<bits/stdc++.h>
using namespace std;
char a[200][200];
int b[200][200];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    int bestX = 1, bestY = 1;
    int best = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i+k<=n)
            {
                bool can=1;
                for (int x=i;x<i+k;x++)
                    if (a[x][j]=='#')
                        can=0;
                if (can)
                {
                    for (int x=i;x<i+k;x++)
                    {
                        b[x][j]++;
                        if (b[x][j]>best)
                            best=b[x][j],bestX = x+1, bestY=j+1;
                    }
                }
            }
            if (j+k<=n)
            {
                bool can=1;
                for (int x=j;x<j+k;x++)
                    if (a[i][x]=='#')
                        can=0;
                if (can)
                {
                    for (int x=j;x<j+k;x++)
                    {
                        b[i][x]++;
                        if (b[i][x]>best)
                            best=b[i][x],bestX = i+1, bestY=x+1;
                    }
                }
            }
        }
    }
    cout<<bestX<<' '<<bestY<<endl;
}