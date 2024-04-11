#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
void add(int &a,int b) {a+=b; if(a>=m) a-=m;}
void dec(int &a,int b) {a-=b; if(a<0) a+=m;}
int dp[MAXN],val[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    dp[1]=1; 
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        add(dp[i],sum);
        add(val[i],val[i-1]);
        add(dp[i],val[i]);
        for(int j=2;i*j<=n;j++)
        {
            add(val[i*j],dp[i]);
            if((i+1)*j<=n) dec(val[(i+1)*j],dp[i]);
        }
        add(sum,dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}