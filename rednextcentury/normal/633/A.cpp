#include <bits/stdc++.h>
using namespace std;
bool dp[100000];
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    dp[0]=1;
    for (int i=0;i<=c;i++)
    {
        if (i>=a)
            dp[i]=dp[i]|dp[i-a];
        if(i>=b)
            dp[i]=dp[i]|dp[i-b];
    }
    if (dp[c])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}