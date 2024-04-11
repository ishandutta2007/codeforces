#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll t=1,k1=1,k2=0;
    ll ans1=0,ans2=0;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]>0) a[i]=1; else a[i]=-1;
        t*=a[i];
        if (t>0)
        {
            ans1+=k1;
            ans2+=k2;
            k1++;
        } else
        {
            ans1+=k2;
            ans2+=k1;
            k2++;
        }
    }
    cout<<ans2<<" "<<ans1<<endl;
}