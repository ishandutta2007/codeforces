#include<iostream>
#define endl "\n"

using namespace std;

long long a[103][103][13];

int main ()
{
    long long n,q,c,i,j,x,y,s,j2,x2,y2,t;

    ios::sync_with_stdio(false);

    cin>>n>>q>>c;

    for(i=0;i<n;i++)
    {
        cin>>x>>y>>s;

        for(j=0;j<=c;j++)
        {
            a[x][y][j]+=s;
            //cout<<x<<" "<<y<<" -- "<<a[x][y][j]<<endl;
            s=(s+1)%(c+1);
        }
    }

    for(i=0;i<=c;i++)
    {
        for(j=1;j<=100;j++)
        {
            for(j2=2;j2<=100;j2++)
            {
                a[j][j2][i]+=a[j][j2-1][i];
            }
        }
    }

    for(i=0;i<=c;i++)
    {
        for(j=1;j<=100;j++)
        {
            for(j2=2;j2<=100;j2++)
            {
                a[j2][j][i]+=a[j2-1][j][i];
            }
        }
    }

    for(i=0;i<q;i++)
    {
        cin>>t>>x>>y>>x2>>y2;

        t%=(c+1);

        //cout<<a[x2][y2][t]<<" h"<<endl;

        cout<<a[x2][y2][t]-a[x2][y-1][t]-a[x-1][y2][t]+a[x-1][y-1][t]<<endl;
    }

    return 0;
}