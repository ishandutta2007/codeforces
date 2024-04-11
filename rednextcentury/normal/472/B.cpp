# include <iostream>
# include <algorithm>
#include <set>
#include <queue>
#include <cstdlib>
using namespace std;
int f[100000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i=0; i<n; i++)
    {
        int j;
        cin>>j;
        f[j]++;
    }
    int ans=0;
    int pp=n;
    while(pp>0)
    {
        int now=k;
        int i=1;
        int mx=-1;
        bool o=0;
        for (i=2000; i>=1; i--)
        {
            if (now>=f[i])
            {
                if (o==0 && (now==0 || f[i]>0))
                {
                    o=1;
                    mx=i;
                }
                now-=f[i];
                pp-=f[i];
                f[i]=0;
            }
            else
            {
                if (o==0 && (f[i]>0 || now==0))
                {
                    o=1;
                    mx=i;
                }
                f[i]-=now;

                pp-=now;
                now=0;
                break;
            }
        }
        ans+=2*(mx-1);
    }
    cout<<ans<<endl;
}