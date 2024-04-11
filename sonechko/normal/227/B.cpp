#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const ll MOD = 1e9 + 7;
#define mod %MOD

const ll N = 1e5 + 11;
int mt[N],a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        mt[a[i]]=i;
    }
    int m;
    cin>>m;
    ll ans1=0,ans2=0;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        ans1+=mt[l];
        ans2+=(n-mt[l]+1);
    }
    cout<<ans1<<" "<<ans2<<endl;
}