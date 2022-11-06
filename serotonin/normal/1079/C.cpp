#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=3e5,m=1e7+7;

int dp[sz][5],a[sz],N;

int fnc(int pos, int n)
{
    if(pos>N) return 1;
    if(dp[pos][n]!=-1) return dp[pos][n];
    dp[pos][n]=0;
    if(a[pos+1]>a[pos]) for(int i=n+1;i<=5;i++) dp[pos][n]|=fnc(pos+1,i);
    else if(a[pos+1]<a[pos]) for(int i=n-1;i>0;i--) dp[pos][n]|=fnc(pos+1,i);
    else for(int i=1;i<=5;i++) if(i!=n) dp[pos][n]|=fnc(pos+1,i);
    return dp[pos][n];
}

int prnt(int pos, int i, int *nxt)
{
    if(dp[pos][i]==1) {
        printf("%d ", i);
        *nxt=i;
        return 1;
    }
    return 0;
}

int main()
{
    cin >> N;
    for(int i=1;i<=N;i++) scanf("%d", &a[i]);
    memset(dp, -1, sizeof(dp));
    int ans=fnc(0,0);
    if(!ans) puts("-1");
    else {
        int n=0;
        for(int pos=0;pos<N;pos++) {
            if(a[pos+1]>a[pos]) {
                for(int i=n+1;i<=5;i++) if(prnt(pos+1,i,&n)) break;
            }
            else if(a[pos+1]<a[pos]) {
                for(int i=n-1;i>0;i--) if(prnt(pos+1,i,&n)) break;
            }
            else for(int i=1;i<=5;i++) if(i!=n && prnt(pos+1,i,&n)) break;
        }
        puts("");
    }
}