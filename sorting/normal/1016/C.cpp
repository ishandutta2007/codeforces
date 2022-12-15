#include<bits/stdc++.h>

using namespace std;

#define N 1000001

long long a[N][2];
long long path[N][2];
long long sum[N][2];

int main ()
{
    long long i,j,n;

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i][0];

    for(i=0;i<n;i++)
        cin>>a[i][1];

    for(i=0;i<2;i++)
    {
        sum[n-1][i]=a[n-1][i]+a[n-1][!i];
        for(j=n-2;j>=0;j--)
            sum[j][i]=sum[j+1][i]+a[j][i]+a[j][!i];

        path[n-1][i]=a[n-1][!i];
        for(j=n-2;j>=0;j--)
            path[j][i]=path[j+1][i]+sum[j+1][i]+a[j][!i]*(2*(n-j)-1);
    }

    long long posx,posy,t=0,res1=0,res2=0;

    posx=0;
    posy=0;

    while(true)
    {
        //cout<<res2<<" res2"<<endl;
        //cout<<res2+path[posx][posy]+sum[posx][posy]*t<<endl;
        if((posx+posy)%2==0)
            res1=max(res1,res2+path[posx][posy]+sum[posx][posy]*t);

        res2+=t*a[posx][posy];

        if(posx==n-1 && posy==n%2)
            break;

        if(posx%2==0 && posy%2==0)
        {
            posy++;
        }
        else
        {
            if(posx%2==0 && posy%2==1)
                posx++;
            else
            {
                if(posx%2==1 && posy%2==1)
                    posy--;
                else
                    posx++;
            }
        }

        t++;
    }

    cout<<max(res1,res2)<<"\n";

    return 0;
}