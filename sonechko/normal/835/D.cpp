#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define ld long double
const int N = 5000 + 11;

ull dp1[N][N];
bool ans1[N][N],ans2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        ull d=0;
        ull p=1;
        for (int j=i; j<s.size(); j++)
        {
            d+=p*(s[j]-'a'+1);
            p*=29;
            dp1[i+1][j+1]=d;
        }
    }
    int ans=0;
    int n=s.size();
    reverse(s.begin(),s.end());
    for (int i=0; i<s.size(); i++)
    {
        ull d=0;
        ull p=1;
        for (int j=i; j<s.size(); j++)
        {
            d+=p*(s[j]-'a'+1);
            p*=29;
            if (dp1[n-j][n-i]==d) {ans++;  ans1[n-j][n-i]=1;}
        }
    }
    cout<<ans<<" ";
    for (int k=2; k<=min(n,13); k++)
    {
        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            ans2[i][j]=ans1[i][j];
            ans1[i][j]=0;
        }
        ans=0;
        for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
        {
            int sz=(j-i+1)/2;
            if (dp1[i][i+sz-1]==dp1[j-sz+1][j]&&ans2[i][i+sz-1]==1)
            {
                ans1[i][j]=1;
                ans++;
            }
        }
        cout<<ans<<" ";
    }
    for (int i=14; i<=n; i++)
        cout<<0<<" ";
}