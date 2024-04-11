#include<bits/stdc++.h>
using namespace std;
long long dp[1000001];
int a[1000000];
vector<int> DIV[1000001];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for (int i=1;i<=1000000;i++)
    {
        for (int j=i;j<=1000000;j+=i)
        {
            DIV[j].push_back(i);
        }
    }
    int n;
    dp[0]=1;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        for (int j=DIV[a[i]].size()-1;j>=0;j--)
        {
            dp[DIV[a[i]][j]]+=dp[DIV[a[i]][j]-1];
            dp[DIV[a[i]][j]]%=1000000007;
        }
    }
    long long ret=0;
    for (int i=1;i<=1000000;i++)
        ret+=dp[i],ret%=1000000007;
    cout<<ret<<endl;
}