#include <iostream>
#include <bits/stdc++.h>
#define dl  double long
#define ll  long long

using namespace std;

int main()
{
    int n;
    long double frac=0;
    long double l,sum=0,maxx=LONG_LONG_MIN,a[1005] ;
    while(cin>>n>>l)
    {
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0; i<n-1; i++)
            maxx=max(maxx,a[i+1]-a[i]);

        long double  ans = maxx /(2*1.0);
        if(a[0]-ans > 0 )
            ans+= (a[0]-ans);

        if ( a[n-1]+ans<=l )
        {
            sum = l -(a[n-1]+ans);
            ans+=sum;
        }

        cout<<setprecision(10)<<fixed<<ans<<endl;
        ans=0,sum=0,maxx=0;
    }
    return 0;
}