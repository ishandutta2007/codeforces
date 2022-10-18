#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mod %MOD

const int N = 18 + 11;
const int M = 5e5 + 11;
const int MOD = 1e9 + 7;

ld a[N][N];
ld dp[M];
ld ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    for (int j=0; j<n; j++)
    cin>>a[i][j];
    dp[(1<<n)-1]=1;
    cout.precision(10);
    cout<<fixed;
    for (int i=(1<<n)-1; i>=1; i--)
    {
        //cout<<i<<" - "<<dp[i]<<endl;
        vector<int> vv;
        for (int j=0; j<n; j++)
        if (i&(1<<j)) vv.pb(j);
        //for (int j=0; j<vv.size(); j++)
        //    cout<<vv[j]<<" ";
        //cout<<endl;
        if (vv.size()>1)
        {
            ld kol=vv.size()*(vv.size()-1)/2;
            for (int j=0; j<vv.size(); j++)
            for (int p=j+1; p<vv.size(); p++)
            {
                int l=vv[j],r=vv[p];
                dp[i^(1<<l)]+=dp[i]*a[r][l]/kol;
                //cout<<"without "<<l<<" - "<<a[r][l]/kol<<endl;
                dp[i^(1<<r)]+=dp[i]*a[l][r]/kol;
                //cout<<"without "<<r<<" - "<<a[l][r]/kol<<endl;
            }
        }
    }
    for (int i=0; i<n; i++)
        cout<<dp[(1<<i)]<<" ";
    cout<<endl;
}