#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 2e5 + 11;

ll a[N],b[N],dp1[20],dp2[20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int t=1; t<=10; t++)
        dp1[t]=-2e9;
    for (int k=1; k<=n; k++)
    {
        int p;
        cin>>p;
        for (int j=1; j<=p; j++)
            cin>>a[j]>>b[j];
        ll c1=-1,cc1=-1,c2=-1,cc2=-1,c3=-1,cc3=-1,mx1=-1,mx2=-1;
        vector<ll> vv;
        for (int j=1; j<=p; j++)
        {
            c1=max(c1,b[j]);
            cc1=max(cc1,b[j]*2ll);
            if (a[j]==1) mx1=max(mx1,b[j]);
            if (a[j]==2) mx2=max(mx2,b[j]);
            if (a[j]==1) vv.pb(b[j]);
        }
        sort(vv.begin(),vv.end());
        if (vv.size()>=3)
        {
            c3=vv[vv.size()-3]+vv[vv.size()-2]+vv[vv.size()-1];
            cc3=vv[vv.size()-3]+vv[vv.size()-2]+vv[vv.size()-1]*2ll;
        }
        for (int j=1; j<=p; j++)
            if (a[j]==3) {} else
            if (a[j]==1)
            {
                if (vv.size()>0&&vv.back()==b[j])
                {
                    if (vv.size()>1) mx1=vv[vv.size()-2]; else mx1=-1;
                }
                if (mx1!=-1)
                {
                    c2=max(c2,mx1+b[j]);
                    cc2=max(cc2,max(mx1,b[j])*2ll+min(mx1,b[j]));
                }
                mx1=vv.back();
                if (mx2!=-1)
                {
                    c2=max(c2,mx2+b[j]);
                    cc2=max(cc2,max(mx2,b[j])*2ll+min(mx2,b[j]));
                }
            } else
            {
                if (mx1!=-1)
                {
                    c2=max(c2,mx1+b[j]);
                    cc2=max(cc2,max(mx1,b[j])*2ll+min(mx1,b[j]));
                }
            }
        for (int t=0; t<=9; t++)
        {
            dp2[t]=-1;
            for (int tt=0; tt<=9; tt++)
            if (dp1[tt]!=-1)
            {
                if (tt==t) dp2[t]=max(dp2[t],dp1[tt]);
                if (tt+1==t&&c1!=-1) dp2[t]=max(dp2[t],dp1[tt]+c1);
                if (tt+1>9&&tt+1-10==t&&cc1!=-1) dp2[t]=max(dp2[t],dp1[tt]+cc1);
                if (tt+2==t&&c2!=-1) dp2[t]=max(dp2[t],dp1[tt]+c2);
                if (tt+2>9&&tt+2-10==t&&cc2!=-1) dp2[t]=max(dp2[t],dp1[tt]+cc2);
                if (tt+3==t&&c3!=-1) dp2[t]=max(dp2[t],dp1[tt]+c3);
                if (tt+3>9&&tt+3-10==t&&cc3!=-1) dp2[t]=max(dp2[t],dp1[tt]+cc3);
            }
        }
        for (int t=0; t<=9; t++)
        {
            dp1[t]=dp2[t];
            ///cout<<k<<" "<<t<<" - "<<dp1[t]<<endl;
        }
    }
    ll ans=0;
    for (int t=0; t<=9; t++)
        ans=max(ans,dp1[t]);
    cout<<ans<<endl;
}