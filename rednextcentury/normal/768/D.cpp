#include<bits/stdc++.h>
using namespace std;
long double dp[20001][1001];
pair<int,int> A[1000000];
int ret[1000000];
int main()
{
    int k,q;
    cin>>k>>q;
    dp[0][0]=1;
    for (int i=1;i<=20000;i++)
        for (int j=1;j<=k;j++)
            dp[i][j]=(dp[i-1][j-1]*(k-j+1))/k + (dp[i-1][j]*j)/k;
    for (int i=0;i<q;i++)
    {
        cin>>A[i].first;
        A[i].second=i;
    }
    sort(A,A+q);
    int l=1;
    for (int i=0;i<q;i++)
    {
        while(dp[l][k]*2000<A[i].first-1e-7)
            l++;
        ret[A[i].second]=l;
    }
    for (int i=0;i<q;i++)
        cout<<ret[i]<<endl;
}