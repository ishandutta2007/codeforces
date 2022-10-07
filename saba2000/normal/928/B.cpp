#include<bits/stdc++.h>
using namespace std;
int dp[100009];
int a[100009];
main()
{
    int n,K;
    cin >> n >> K;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i =1; i <= n; i++)
    {
        int P = a[i];
        int l = max(P + K + 1, i - K);
        if(P == 0) l = max(1, i - K);
        if(l> n) {dp[i] = dp[P]; continue;}
        int r = min(i + K, n);
        dp[i]= r-l+1+dp[P];
    }
    for (int i=1; i<= n; i++)
        cout<<dp[i]<<" ";
    cout << endl;
}