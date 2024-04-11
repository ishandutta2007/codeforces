#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define mod %MOD

const int MOD = 1e9 + 7;
const int N = 1e6 + 11;

int a[N],b[N];
int dp[N][4],pr[N][4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    n--;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        cin>>b[i];
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[0][3]=1;
    for (int i=1; i<=n; i++)
    for (int j=0; j<=3; j++)
    for (int p=0; p<=3; p++)
    if (a[i]==(j|p)&&b[i]==(j&p)&&dp[i-1][j]==1)
    {
        dp[i][p]=1;
        pr[i][p]=j;
    }
    for (int i=0; i<=3; i++)
        if (dp[n][i]==1)
    {
        cout<<"YES"<<endl;
        vector<int> v;
        int c=i;
        for (int j=n; j>=0; j--)
        {
            v.pb(c);
            c=pr[j][c];
        }
        for (int i=v.size()-1; i>=0; i--)
            cout<<v[i]<<" ";
        cout<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
}