#include<bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N];
int dp1[N],dp2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    dp1[0]=1;
    for (int i=1; i<=n; i++)
    {
        vector<int> v;
        int m;
        cin>>m;
        for (int j=1; j<=(int)sqrt(m); j++)
            if (m%j==0)
        {
            v.pb(j);
            if (m/j!=j) v.pb(m/j);
        }
        for (int j=0; j<v.size(); j++)
            dp2[v[j]]+=dp1[v[j]-1];
        for (int j=0; j<v.size(); j++)
            {
                dp1[v[j]]=(dp1[v[j]]+dp2[v[j]])%MOD;
                dp2[v[j]]=0;
            }
    }
    int ans=0;
    for (int i=1; i<=1000000; i++)
        ans=(ans+dp1[i])%MOD;
    cout<<ans<<endl;
}