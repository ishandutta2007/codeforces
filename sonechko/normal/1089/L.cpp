#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define ld long double
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 998244353;

int kol[N],a[N];
pair<int,int> b[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        kol[a[i]]++;
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i].ff;
        b[i].ss=i;
    }
    sort(b+1,b+n+1);
    int t=0;
    for (int i=1; i<=k; i++)
        if (kol[i]==0) t++;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        int l=b[i].ss;
        if (kol[a[l]]>1&&t>0)
        {
            kol[a[l]]--;
            ans+=1ll*b[i].ff;
            t--;
        }
    }
    cout<<ans<<endl;
}