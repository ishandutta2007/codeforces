#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define ld long double
const int N = 2e5 + 11;

bool use[N];
int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ll kol=0;
    vector<int> v;
    for (int i=1; i<=n; i++)
        if (a[i]==kol) {use[i]=1; kol++;} else
        if (a[i]<kol) v.pb(i); else
    {
        while (a[i]>kol)
        {
            int d=v.back();
            use[d]=1;
            v.pop_back();
            kol++;
        }
        use[i]=1;
        kol++;
    }
    kol=0;
    ll ans=0;
    for (int i=1; i<=n; i++)
    {
        if (use[i]==1) kol++;
        ans+=kol-a[i]-1;
    }
    cout<<ans<<endl;
}