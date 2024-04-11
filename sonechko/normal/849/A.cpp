#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 11;
int dp[N][N],a[N];
int main()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    cin>>a[i];
    dp[0][0]=1;
    for (int i=1; i<=n; i++)
    for (int kol=1; kol<=i; kol++)
    {
        for (int j=0; j<i; j++)
        if (dp[j][kol-1]==1&&a[j+1]%2==1&&a[i]%2==1&&(i-j)%2==1) dp[i][kol]=1;
    }
    for (int kol=1; kol<=n; kol+=2)
    if (dp[n][kol]==1) {cout<<"Yes"<<endl; return 0;}
    cout<<"No"<<endl;
}