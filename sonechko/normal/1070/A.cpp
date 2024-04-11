#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 3e6 + 11;

int dp[511][5011],use[511][5011];
int pr1[511][5011],pr2[511][5011],c[511][5011];
vector<int> ost,sum;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d,s;
    cin>>d>>s;
    use[0][0]=1;
    ost.pb(0);
    sum.pb(0);
    for (int j=0; j<ost.size(); j++)
    {
        int ost1=ost[j],sum1=sum[j];
        int ans=dp[ost1][sum1];
        for (int p=0; p<=9; p++)
        {
            int ost2=(ost1*10+p)%d;
            int sum2=sum1+p;
            if (sum2<=s&&use[ost2][sum2]==0)
            {
                use[ost2][sum2]=1;
                dp[ost2][sum2]=ans+1;
                pr1[ost2][sum2]=ost1;
                pr2[ost2][sum2]=sum1;
                c[ost2][sum2]=p;
                ost.pb(ost2);
                sum.pb(sum2);
            }
        }
    }
    if (use[0][s]==0) {cout<<"-1"<<endl; return 0;}
    string ans="";
    int ost1=0,sum1=s;
    while (ost1!=0||sum1!=0)
    {
        char ch=(c[ost1][sum1]+'0');
        ans+=ch;
        int t1=pr1[ost1][sum1];
        int t2=pr2[ost1][sum1];
        ost1=t1;
        sum1=t2;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}