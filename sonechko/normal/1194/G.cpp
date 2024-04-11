#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100 + 11;
const int MOD = 998244353;

int dp[N][10][10][2][2][17][17];
string s;
int n;
int ans;
int nn;
int num1[N],num2[N];


void up(int xx, int yy)
{
    if (xx==1&&yy==1)
    {
        ll d=0;
        for (int j=1; j<=n; j++)
            d=(d*1ll*10+s[j]-'0')%MOD;
        ans=(ans+d)%MOD;
        return;
    }
    vector<int> v1,v2;
    for (int j=0; j<=9; j++)
    {
        num1[j]=-1;
        num2[j]=-1;
    }
    for (int t=1; t<=10; t++)
    {
        int x1=xx*t;
        int y1=yy*t;
        if (x1>9) continue;
        if (y1>9) continue;
        v1.pb(x1);
        v2.pb(y1);
        num1[x1]=v1.size()-1;
        num2[y1]=v2.size()-1;
    }
    int m=v1.size();
    for (int i=0; i<=n+1; i++)
    for (int ost1=0; ost1<=9; ost1++)
    for (int ost2=0; ost2<=9; ost2++)
    for (int d1=0; d1<=1; d1++)
    for (int d2=0; d2<=1; d2++)
    for (int mask1=0; mask1<(1<<m); mask1++)
    for (int mask2=0; mask2<(1<<m); mask2++)
        dp[i][ost1][ost2][d1][d2][mask1][mask2]=0;
    dp[n+1][0][0][1][1][0][0]=1;
    for (int i=n; i>=1; i--)
    for (int ost1=0; ost1<=9; ost1++)
    for (int ost2=0; ost2<=9; ost2++)
    for (int d1=0; d1<=1; d1++)
    for (int d2=0; d2<=1; d2++)
    for (int mask1=0; mask1<(1<<m); mask1++)
    for (int mask2=0; mask2<(1<<m); mask2++)
    {
        for (int c=0; c<=9; c++)
        {
            int c1=(c*xx+ost1)%10;
            int ost11=(c*xx+ost1)/10;
            int c2=(c*yy+ost2)%10;
            int ost22=(c*yy+ost2)/10;
            int dd1=d1,dd2=d2;
            if (c1<s[i]-'0') dd1=1;
            if (c2<s[i]-'0') dd2=1;
            if (c1>s[i]-'0') dd1=0;
            if (c2>s[i]-'0') dd2=0;
            int mask11=mask1,mask22=mask2;
            if (num1[c1]!=-1) mask11|=(1<<num1[c1]);
            if (num2[c2]!=-1) mask22|=(1<<num2[c2]);
            /**
            for (int j=0; j<v1.size(); j++)
            {
                if (c1==v1[j]) mask11|=(1<<j);
                if (c2==v2[j]) mask22|=(1<<j);
            }
            ///447370997
            **/
            dp[i][ost11][ost22][dd1][dd2][mask11][mask22]=
            (dp[i][ost11][ost22][dd1][dd2][mask11][mask22]+
             dp[i+1][ost1][ost2][d1][d2][mask1][mask2])%MOD;
        }
    }
    for (int mask1=0; mask1<(1<<m); mask1++)
    for (int mask2=0; mask2<(1<<m); mask2++)
    {
        int p=0;
        for (int j=0; j<v1.size(); j++)
            if ((mask1&(1<<j))&(mask2&(1<<j))) p=1;
        if (p==1) ans=(ans+dp[1][0][0][1][1][mask1][mask2])%MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    s="."+s;
    for (int xx=1; xx<=9; xx++)
    for (int yy=1; yy<=9; yy++)
        if (__gcd(xx,yy)==1) up(xx,yy);
    cout<<ans;
}