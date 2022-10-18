#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const ll MOD = 998244353;

ll dp[N][2][2];

bool step(int x)
{
    while (x%2==0)
        x/=2;
    return (x==1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
vector<int> ans;
ans.pb(1);
ans.pb(2);
ans.pb(4);
ans.pb(5);
ans.pb(9);
ans.pb(10);
ans.pb(20);
ans.pb(21);
ans.pb(41);
ans.pb(42);
ans.pb(84);
ans.pb(85);
ans.pb(169);
ans.pb(170);
ans.pb(340);
ans.pb(341);
ans.pb(681);
ans.pb(682);
ans.pb(1364);
ans.pb(1365);
ans.pb(2729);
ans.pb(2730);
ans.pb(5460);
ans.pb(5461);
ans.pb(10921);
ans.pb(10922);
ans.pb(21844);
ans.pb(21845);
ans.pb(43689);
ans.pb(43690);
ans.pb(87380);
ans.pb(87381);
ans.pb(174761);
ans.pb(174762);
ans.pb(349524);
ans.pb(349525);
ans.pb(699049);
ans.pb(699050);
for (int i=0; i<ans.size(); i++)
if (ans[i]==n) {cout<<1; return 0;}
cout<<0;
return 0;
    int l=1,r=1,t=1;
    dp[0][0][0]=1;
    dp[0][1][0]=1;
    dp[0][0][1]=1;
    dp[0][1][1]=1;
    for (int i=1; i<=n; i++)
    {
        if (i==1) {} else
        if (t==1)
        {
            if (l==r||(!step(r))) r++; else
            {
                l++;
                t=2;
            }
        } else
        {
            if (l==r) {t=1; r++;} else l++;
        }

        ///cout<<l<<".."<<r<<endl;

        for (int pos=l; pos<=r; pos++)
        {
            if (pos%2==1)
            {
                dp[i][0][0]+=dp[pos-1][0][1]*dp[i-pos][1][0];
                dp[i][1][1]+=dp[pos-1][1][0]*dp[i-pos][0][1];
            } else
            {
                dp[i][0][1]+=dp[pos-1][0][0]*dp[i-pos][0][1];
                dp[i][1][0]+=dp[pos-1][1][1]*dp[i-pos][1][0];
            }
            if (dp[i][0][0]>998244353000000000)
                dp[i][0][0]-=998244353000000000;
            if (dp[i][0][1]>998244353000000000)
                dp[i][0][1]-=998244353000000000;
            if (dp[i][1][0]>998244353000000000)
                dp[i][1][0]-=998244353000000000;
            if (dp[i][1][1]>998244353000000000)
                dp[i][1][1]-=998244353000000000;
        }
        dp[i][0][0]%=MOD;
        dp[i][0][1]%=MOD;
        dp[i][1][0]%=MOD;
        dp[i][1][1]%=MOD;
        ///cout<<i<<": "<<dp[i][0][0]<<" "<<dp[i][0][1]<<" "<<dp[i][1][0]<<" "<<dp[i][1][1]<<"\n";
        if ((dp[i][1][0]+dp[i][1][1])%MOD>0)
        {
            cout<<"//"<<i<<": "<<(dp[i][1][0]+dp[i][1][1])%MOD<<endl;
            cout<<"ans.pb("<<i<<");"<<endl;
        }
    }
    cout<<(dp[n][1][0]+dp[n][1][1])%MOD;
}
/**
l .. r
l - 
 
**/