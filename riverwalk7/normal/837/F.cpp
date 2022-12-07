#include <iostream>
#include <fstream>
#include <queue>
#define MAXN 200100
using namespace std;
typedef long long ll;
int N;
ll K;
ll a[MAXN];
ll ans;
ll cur;
int main()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        cin>>a[i];
        if(a[i]==0&&i==1)
        {
            i--;
            N--;
        }
        if(a[i]>=K)
        {
            cout<<0<<endl;
            return 0;
        }
    }
    if(N>=4)
    {
        while(true)
        {
            ans++;
            for(int i=1; i<=N; i++)
            {
                a[i] += a[i-1];
                if(a[i]>=K)
                {
                    cout<<ans<<endl;
                    return 0;
                }
            }
        }
    }
    else
    {
        if(N==2)
        {
            ans = (K-a[2]+a[1]-1)/a[1];
            cout<<ans<<endl;
            return 0;
        }
        if(N==3)
        {
            ll lbound, hbound;
            lbound = 0;
            hbound = 1500000000;
            while(lbound!=hbound)
            {
                ans = (lbound + hbound)/2;
                cur = K - a[2]*ans - a[3];
                cur--;
                if(cur / (ans*(ans+1)/2) < a[1])
                {
                    hbound = ans;
                }
                else
                {
                    lbound = ans + 1;
                }
            }
            cout<<lbound<<endl;
            return 0;
        }
    }
}