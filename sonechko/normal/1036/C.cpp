#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e4 + 11;

ll dp[N][5];

ll get(ll n)
{
    string s="";
    while (n>0)
    {
        s+=char(n%10+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    int t=0;
    ll ans=0;
    for (int j=0; j<s.size(); j++)
    {
        for (int d=0; d<s[j]-'0'; d++)
        {
            if (d!=0) t++;
            for (int k=0; k+t<=3; k++)
                ans+=dp[s.size()-j-1][k];
            if (d!=0) t--;
        }
        if (s[j]!='0') t++;
    }
    if (t<=3) ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    dp[0][0]=1;
    for (int i=1; i<=20; i++)
    for (int p=0; p<=9; p++)
    for (int k=0; k<=3; k++)
    {
        int c=k;
        if (p!=0) c++;
        dp[i][c]+=dp[i-1][k];
    }
    while (t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<get(r)-get(l-1)<<"\n";
    }
}