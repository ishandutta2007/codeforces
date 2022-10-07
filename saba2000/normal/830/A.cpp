#include<bits/stdc++.h>
using namespace std;
main()
{long long a[2000],b[4000];
    int n,k,p;
    cin>>n>>k>>p;
    for(int i=0; i<n; i++)
        cin>>a[i];
        sort(a,a+n);
    for (int i=0; i<k; i++)
        cin>>b[i];
    sort(b,b+k);
    long long ans=1e18;
    for(int i=0; i<=k-n; i++) {long long s=0;
        for (int j=0; j<n; j++)//j--i+j
            s=max(s,abs(a[j]-b[i+j])+abs(b[i+j]-p));
        ans=min(ans,s);
    }
    cout<<ans<<endl;


}