#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD = 998244353;
const int N = 500 + 11;

int c[N];
ll dp[N][N];
bool d[N][N];

ll rec(int l, int r)
{
    if (d[l][r]) return dp[l][r];
    if (l>r) return 1;
    if (l==r) return 1;
    d[l][r]=1;
    dp[l][r]=0;
    int pos=l;
    for (int j=l; j<=r; j++)
        if (c[j]<c[pos]) pos=j;
    ll dp1=0,dp2=0;
    for (int p1=l; p1<=pos; p1++)
        dp1=(dp1+rec(l,p1-1)*rec(p1,pos-1))%MOD;
    for (int p2=pos; p2<=r; p2++)
        dp2=(dp2+rec(pos+1,p2)*rec(p2+1,r))%MOD;
    dp[l][r]=(dp1*dp2)%MOD;
    return dp[l][r];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        cin>>c[i];
    cout<<rec(1,n);
}


/**

dp l r k

l .. r k



**/