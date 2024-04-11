#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin >> n;
    int ans=0;
    for (int i=0;i <= n; i++)
    {
        for (int j =i; j<=n; j++)
        {
            int k=(i^j);
            if(k>=j && i+j>k && k<=n) ans++;
        }
    }
    cout<<ans<<endl;
}