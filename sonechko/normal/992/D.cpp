#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 3e5 + 11;
const int MOD = 1e9 + 7;
const int MX = 2e18;

#define mod %MOD

ll a[N],nx[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int p=n+1;
    for (int i=n; i>=1; i--)
    {
        nx[i]=p;
        if (a[i]>1) p=i;
    }
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        ll p=1,s=0;
        for (int j=i; j<=n; j=nx[j])
        {
            if (MX/a[j]+5<p) break;
            p*=a[j];
            s+=a[j];
            int d=nx[j];
            if (p%k==0)
            {
                ll ss=p/k;
                ll kk=nx[j]-j-1;
                if (ss>=s&&ss<=s+kk) ans++;
            }
            s+=nx[j]-j-1;
        }
    }
    cout<<ans<<endl;
}


/// 992 D