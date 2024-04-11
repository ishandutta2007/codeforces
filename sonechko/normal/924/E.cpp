#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ff first
#define ss second
#define pb push_back

const int N = 10000 + 11;

int dp[N];
bool d[N];
int a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    swap(l,r);
    int p=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        p+=a[i];
    }
    l=p-l;
    r=p-r;
    vector<int> v1,v2;
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        if (b[i]==0) v1.pb(a[i]); else v2.pb(a[i]);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    d[0]=1;
    dp[0]=0;
    int mx=0;
    for (int j=0; j<v1.size(); j++)
    {
        for (int p=mx; p>=0; p--)
            if (d[p]) d[p+v1[j]]=1;
        mx+=v1[j];
    }
    for (int j=0; j<v2.size(); j++)
    {
        for (int p=mx; p>=0; p--)
            if (d[p])
        {
            int c=dp[p];
            if (p+v2[j]>=l&&p+v2[j]<=r) c++;
            if (d[p+v2[j]]==0||dp[p+v2[j]]<c)
            {
                d[p+v2[j]]=1;
                dp[p+v2[j]]=c;
            }
        }
        mx+=v2[j];
    }
    int ans=0;
    for (int x=0; x<=mx; x++)
        ans=max(ans,dp[x]);
    cout<<ans<<endl;
}
/**
1 1 1
1
1
**/