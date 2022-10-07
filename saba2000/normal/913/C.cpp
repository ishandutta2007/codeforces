#include<bits/stdc++.h>
using namespace std;
long long c[200009];
main()
{
    long long n, L;
    cin >>n >> L;
    for (long long i=0; i<n; i++)
        cin >>c[i];
    for (long long i=n; i<=30; i++)
        c[i] = 2*c[i-1];
    long long ans=0;
    for (long long i=0; i<=30; i++)
    {
        if(i!=0) c[i] = min (c[i], 2*c[i-1]);
        if((1<<i)&L)
            ans += c[i];
        else ans=min(ans,c[i]);

    }
    cout << ans<<endl;
}