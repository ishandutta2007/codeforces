#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

bool use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=m;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        for (int j=l; j<=r; j++)
        {
            if (use[j]==0&&j<=m) ans--;
            use[j]=1;
        }
    }
    cout<<ans<<endl;
    for (int j=1; j<=m; j++)
        if (use[j]==0) cout<<j<<" ";
}