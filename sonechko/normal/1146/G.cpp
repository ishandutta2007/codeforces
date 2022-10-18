#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 50 + 11;

int l[N],r[N],x[N],c[N];
int dp[N][N][N];
bool cc[N][N][N];
int m;

int rec(int l1, int r1, int p)
{
    if (l1>r1||p==0) return 0ll;
    if (cc[l1][r1][p]) return dp[l1][r1][p];
    dp[l1][r1][p]=rec(l1,r1,p-1);
    cc[l1][r1][p]=1;
    for (int pos=l1; pos<=r1; pos++)
    {
        int res=rec(l1,pos-1,p-1)+rec(pos+1,r1,p)+p*p;
        for (int j=1; j<=m; j++)
            if (l[j]<=pos&&pos<=r[j]&&l[j]>=l1&&r[j]<=r1&&x[j]<=p-1)
                res-=c[j];
        dp[l1][r1][p]=max(dp[l1][r1][p],res);
    }
    return dp[l1][r1][p];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,h,mm;
    cin>>n>>h>>m;
    for (int i=1; i<=m; i++)
    {
        cin>>l[i]>>r[i]>>x[i]>>c[i];
    }
    int ans=rec(1,n,h);
    cout<<ans<<endl;
}