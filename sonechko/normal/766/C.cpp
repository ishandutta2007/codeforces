
#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define y1 khdifkne
#define ll long long
#define ld long double
ll a[N],b[N],dp[N];
bool god[N][N];
string s;
int main()
{
    int n;
    cin>>n;
    cin>>s;
    s='.'+s;
    for (int i=0; i<26; i++)
        cin>>a[i];
    dp[0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<26; j++)
            b[j]=0;
        for (int j=i; j<=n; j++)
        {
            b[s[j]-'a']++;
            int f=0;
            for (int k=0; k<26; k++)
            if (b[k]>0&&a[k]<j-i+1) f=1;
            if (f==1) break;
            god[i][j]=1;
        }
    }
    for (int i=1; i<=n; i++)
    for (int j=i; j>=1; j--)
    if (god[j][i]==1) dp[i]=(dp[i]+dp[j-1])mod;
    cout<<dp[n]<<endl;
    int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++)
    if (god[i][j]==1) {ans=max(ans,j-i+1);}
    cout<<ans<<endl;
    int l=1,kol=0;
    while (l<=n)
    {
        kol++;
        for (int j=n; j>=l; j--)
        if (god[l][j]==1) {l=j+1; break;}
    }
    cout<<kol<<endl;
}