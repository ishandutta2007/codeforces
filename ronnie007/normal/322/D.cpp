#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 105
#define INF 1000000000

using namespace std;
template <class T> void chmax(T&a,T b){a=max(a,b);}

int at[SIZE],df[SIZE];
int st[SIZE],gd[SIZE];
char in[5];
int dp[SIZE];

int main()
    {
    int n,m;
    scanf("%d %d",&n,&m);
    int as=0,ds=0;
    for(int i=0;i<n;i++)
        {
        int s;
        scanf("%s %d",&in,&s);
        if(in[0]=='A') at[as++]=s;
        else df[ds++]=s;
        }
    for(int i=0;i<m;i++) scanf("%d",&st[i]);
    sort(at,at+as);
    sort(df,df+ds);
    sort(st,st+m);
    int ret=0;
    for(int i=0;i<=ds;i++)
        {
        int pos=0,per=0;
        for(int j=0;j<m;j++)
            {
            if(pos<i&&st[j]>df[pos]) pos++;
            else gd[per++]=st[j];
            }
        if(pos<i) break;
        for(int j=1;j<=as;j++) dp[j]=-INF;
        dp[0]=0;
        for(int j=0;j<per;j++)
            {
            for(int k=as-1;k>=0;k--)
                {
                if(gd[j]>=at[k]) chmax(dp[k+1],dp[k]+gd[j]-at[k]);
                }
            }
        if(i==ds&&dp[as]>=0)
            {
            dp[as]=0;
            for(int j=0;j<per;j++) dp[as]+=gd[j];
            for(int j=0;j<as;j++) dp[as]-=at[j];
            }
        for(int j=0;j<=as;j++) chmax(ret,dp[j]);
        }
    printf("%d\n",ret);
    return 0;
    }