#include<bits/stdc++.h>
using namespace std;
int a[200214];
main()
{
    int n;
    cin >> n;
    int M = 1e9;
    for (int i =0 ; i < n ; i++)
    {
        cin  >>a[i];
        M =min(M,a[i]);
    }
    int L = -10000000;
    int ans = 10000000;
    for (int i =0; i  < n; i++)
    {
        if(a[i ] == M) ans=min(ans,i-L),L=i;
    }
    cout<<ans<<endl;
}