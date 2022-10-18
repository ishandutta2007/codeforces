#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define ss second
#define ff first
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 2e5 + 11;
int a[5][5],b[5][5];
int dp[5][5];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll k;
    int a1,b1;
    cin>>k>>a1>>b1;

    for (int i=1; i<=3; i++)
    for (int j=1; j<=3; j++)
    cin>>a[i][j];

    for (int i=1; i<=3; i++)
    for (int j=1; j<=3; j++)
    cin>>b[i][j];

    vector<int> v1,v2;
    ll ans1=0,ans2=0;

    for (int p=1; p<=100; p++)
    {
        if ((a1==3&&b1==2)||(a1==2&&b1==1)||(a1==1&&b1==3)) ans1++;
        if ((b1==3&&a1==2)||(b1==2&&a1==1)||(b1==1&&a1==3)) ans2++;
        int x1=a[a1][b1];
        int y1=b[a1][b1];
        if (p==k) break;
        if (dp[x1][y1]==0)
        {
            dp[x1][y1]=1;
            v1.pb(x1);
            v2.pb(y1);
            a1=x1;
            b1=y1;
        } else
        {
            k-=p;
            int num=0;
            for (int i=0; i<v1.size(); i++)
            if (v1[i]==x1&&v2[i]==y1) {num=i; break;}
            ll d=v1.size()-num;
            ll rr1=0,rr2=0;
            for (int i=num; i<v1.size(); i++)
            {
                a1=v1[i];
                b1=v2[i];
                if ((a1==3&&b1==2)||(a1==2&&b1==1)||(a1==1&&b1==3)) rr1++;
                if ((b1==3&&a1==2)||(b1==2&&a1==1)||(b1==1&&a1==3)) rr2++;
            }
            ans1+=rr1*(k/d);
            ans2+=rr2*(k/d);
            k-=k/d*d;
            for (int i=num; i<v1.size(); i++)
            {
                if (k==0) break;
                a1=v1[i];
                b1=v2[i];
                if ((a1==3&&b1==2)||(a1==2&&b1==1)||(a1==1&&b1==3)) ans1++;
                if ((b1==3&&a1==2)||(b1==2&&a1==1)||(b1==1&&a1==3)) ans2++;
                k--;
            }
            break;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}