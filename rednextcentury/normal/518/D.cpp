    #include <bits/stdc++.h>
    using namespace std;
    long double dp[2003][2004];
    bool vis[2003][2002];
    int n,t;
    long double p;
    long double solve(int i,int j)
    {
        if (i==0 || j==0)return n-j;
        if (vis[i][j])return dp[i][j];
vis[i][j]=1;
        dp[i][j] = p*solve(i-1,j-1)+(1-p)*solve(i-1,j);
        return dp[i][j];
    }
    int main()
    {
        cin>>n>>p>>t;
        cout<<setprecision(10)<<fixed<<solve(t,n)<<endl;
    }