#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=m;
    for (int i=1; i<=n; i++)
    {
        int l;
        cin>>l;
        if (m%l==0) ans=min(ans,m/l);
    }
    cout<<ans<<endl;
}