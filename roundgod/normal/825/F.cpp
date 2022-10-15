#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int dp[MAXN];
vector<int> prefix_function(string &a)
{
    int n=a.size();
    vector<int> next(n+1,0);
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(a[j]==a[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
    return next;
}
int cal(int x)
{
    int ans=1;
    while(x>=10) x/=10,ans++;
    return ans;
}
int main()
{
    cin>>str;
    n=(int)str.size();
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        dp[i+1]=INF;
        string s=str.substr(0,i+1);
        reverse(s.begin(),s.end());
        vector<int> pre=prefix_function(s);
        for(int j=0;j<=i;j++)
        {
            int len=i-j+1-pre[i-j+1];
            //printf("i=%d j=%d len=%d\n",i,j,len);
            if((i-j+1)%len==0) dp[i+1]=min(dp[i+1],dp[j]+cal((i-j+1)/len)+len); else dp[i+1]=min(dp[i+1],dp[j]+i-j+2);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}