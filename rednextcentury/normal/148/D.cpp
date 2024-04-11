#include <bits/stdc++.h>
using namespace std;
long double dp[2003][2004][2];
bool vis[2003][2002][2];
long double P(int i,int j,int p)
{
    if (p==0)
        return i/(i+j+0.0);
    else
        return j/(i+j+0.0);
}
long double solve(int i,int j,int turn)
{
    if (i<=0)return 0;
    if (j<=0)return turn;
    if (vis[i][j][turn])return dp[i][j][turn];
    vis[i][j][turn]=1;
    long double white = P(i,j,0);
    long double black = P(i,j,1);
    if (turn==0)
        dp[i][j][turn] = black*(P(i,j-1,0)*solve(i-1,j-1,1-turn) + P(i,j-1,1)*solve(i,j-2,1-turn));
    else
        dp[i][j][turn] = white+black*solve(i,j-1,1-turn);
    return dp[i][j][turn];
}
int main()
{

    int w,b;
    cin>>w>>b;
    cout<<setprecision(10)<<fixed<<solve(w,b,1)<<endl;
}