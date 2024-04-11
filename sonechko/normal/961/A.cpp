#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 3e6 + 11;

int a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int l;
        cin>>l;
        a[l]++;
    }
    int ans=a[1];
    for (int i=1; i<=n; i++)
        ans=min(ans,a[i]);
    cout<<ans<<endl;
}