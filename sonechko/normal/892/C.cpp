#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 1e5 + 11;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int kol=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]==1) kol++;
    }
    if (kol!=0)
    {
        cout<<n-kol<<endl;
        return 0;
    }
    int ans=n*n;
    for (int i=1; i<=n; i++)
    {
        int res=0;
        int d=a[i];
        for (int j=i+1; j<=n; j++)
        {
            d=__gcd(d,a[j]);
            if (d==1) {ans=min(ans,n+res); break;}
            res++;
        }
    }
    if (ans==n*n) cout<<-1<<endl; else cout<<ans<<endl;
}