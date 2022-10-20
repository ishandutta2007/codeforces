#include<iostream>
#include<stdio.h>
using namespace std;

#define INPROGRESS -4
#define UNKNOWN -3
#define INFINITE -2

#define ADD 1
#define SUBTRACT 0


int  n;
long long a[2*131072];

long long dp[2*131072][2];


void input();
void solve();
long long dfs(pair < int   , int > state);


int main()
    {
    input();
    solve();
    return 0;
    }


void input()
    {
    scanf("%d",&n);
    int i;
    for(i=2;i<=n;i++)
        {
        scanf("%d",&a[i]);
        }
    }


void solve()
    {
    int i;
    for(i=1;i<=n;i++)
        {
        dp[i][ADD]=UNKNOWN;
        dp[i][SUBTRACT]=UNKNOWN;
        }
    for(i=2;i<=n;i++)
        {
        dfs(make_pair(i,ADD));
        dfs(make_pair(i,SUBTRACT));
        }
    long long ans;

    for(i=1;i<=n-1;i++)
        {
        if(dp[i+1][SUBTRACT]!=INFINITE)
            {
            ans=i+dp[i+1][SUBTRACT];
            cout<<ans<<"\n";
            }
        else printf("-1\n");
        }
    }


long long dfs(pair < int , int > state)
    {
    //printf("%I64d %I64d\n",state.first,state.second);
    if(state.first<=0 || state.first>n)return 0;
    if(state.first==1 && state.second==ADD)return INFINITE;
    if(dp[state.first][state.second]==INPROGRESS)return INFINITE;
    if(dp[state.first][state.second]!=UNKNOWN)return dp[state.first][state.second];
    dp[state.first][state.second]=INPROGRESS;
    //printf("  %I64d %I64d\n",state.first,state.second);
    long long next,x=state.first;
    if(state.second==SUBTRACT)
        {
        next=x-a[x];
        }
    else next=x+a[x];
    //printf("%I64d\n",a[state.first]);
    long long ans=dfs(make_pair(next,1-state.second));
    if(ans==INFINITE)dp[state.first][state.second]=INFINITE;
    else dp[state.first][state.second]=a[state.first]+ans;
    return dp[state.first][state.second];
    }