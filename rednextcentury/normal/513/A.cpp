# include <iostream>
# include <algorithm>
# include <vector>
# include <cstring>
using namespace std;
int dp[100][100][2];
int k1,k2;
int solve(int n1,int n2,int turn)
{
    if (turn==0 && n1<=0)
        return 1;
    if (turn==1 && n2<=0)
        return 0;
    int& ret=dp[n1][n2][turn];
    if (ret!=-1)
        return ret;
    ret=1-turn;
    if (turn==0)
    {
    for (int i=1;i<=k1;i++)
    {
        int now=solve(n1-i,n2,1-turn);
        if (now==turn)
            ret=now;
    }
    }
    else
    {
    for (int i=1;i<=k2;i++)
    {
        int now=solve(n1,n2-i,1-turn);
        if (now==turn)
            ret=now;
    }
    }
    return ret;
}
int main()
{
    int n1,n2;
    cin>>n1>>n2>>k1>>k2;
    if (n1<=n2)
        cout<<"Second"<<endl;
    else
        cout<<"First"<<endl;
}