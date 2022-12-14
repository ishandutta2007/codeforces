#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
long  long  num[1000001];
long  long   cur[1000001];
int vis[1000000];
int main()
{
    long  long  n;
    cin>>n;
    for (long  long i=1;i<=n;i++)
    {
        long  long x;
        cin>>x;
        long  long    j=0;
        long  long y=x;
        while(x<=1000000)
        {
            num[x]+=j;
            cur[x]++;
            vis[x]=i;
            j++;
            x*=2;
        }
        j=1;
        x=y/2;
        while(x>=0)
        {
            num[x]+=j;
            cur[x]++;
            vis[x]=i;
            if (x==0)
                break;
            int h=j+1;
            int k=x*2;
            while(k<=100000)
            {
                if (vis[k]!=i)
                {
                num[k]+=h;
                cur[k]++;
                }
                vis[k]=i;
                k*=2;


                h++;
            }
            j++;
            x/=2;
        }
    }
    long  long ans=100000000;
    for (long  long i=0;i<=1000000;i++)
    {
        if (cur[i]==n)

            ans=min(ans,num[i]);
    }
    cout<<ans<<endl;
}