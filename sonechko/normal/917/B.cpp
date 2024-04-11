#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const ll N = 100 + 11;
const ll mod = 1e9 + 7;

int dp[N][N][28];
vector<int> v[N],w[N];

int rec(int j, int d, int i)
{
    if (dp[j][d][i]!=0) return dp[j][d][i];
    for (int k=0; k<v[j].size(); k++)
        if (w[j][k]>=i)
        {
            int x=rec(d,v[j][k],w[j][k]);
            if (x==1) {dp[j][d][i]=2; return 2;}
        }
    dp[j][d][i]=1;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l,r;
        char ch;
        cin>>l>>r>>ch;
        v[l].pb(r);
        w[l].pb(ch-'a');
    }
    for (int i=26; i>=0; i--)
    for (int j=1; j<=n; j++)
    for (int d=1; d<=n; d++)
        int x=rec(j,d,i);
    for (int j=1; j<=n; j++)
    {
        for (int d=1; d<=n; d++)
        if (dp[j][d][0]==1) cout<<'B'; else cout<<'A';
        cout<<endl;
    }
}