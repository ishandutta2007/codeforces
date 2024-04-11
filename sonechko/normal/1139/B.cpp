#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 2e5 +  11;

ll a[N],ans;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    ans=0;
    ll maxx=2e9;
    for (int i=n; i>=1; i--)
    {
        maxx=min(maxx,a[i]);
        ans+=maxx;
        maxx--;
        if (maxx<0) maxx=0;
    }
    cout<<ans<<endl;
}