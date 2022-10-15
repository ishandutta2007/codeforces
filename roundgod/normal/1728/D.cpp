#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
int dp[MAXN][MAXN];
int check(int l,int r,int x,int y)
{
    if(dp[l][r]!=0) return dp[l][r];
    if(str[x]==str[y]) return 0; else return str[x]<str[y]?1:-1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        int n=(int)str.size();
        for(int i=0;i<n-1;i++)
            dp[i][i+1]=(str[i]==str[i+1]?0:1);
        for(int len=4;len<=n;len+=2)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j=i+len-1;
                dp[i][j]=max(min(check(i+2,j,i,i+1),check(i+1,j-1,i,j)),min(check(i,j-2,j,j-1),check(i+1,j-1,j,i)));
            }
        }
        if(dp[0][n-1]==0) puts("Draw"); else if(dp[0][n-1]==1) puts("Alice"); else puts("Bob");
    }
    return 0;
}