#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,a;
    cin>>n>>m>>a;
    int ans=0;
    int p=0;
    for (int i=1; i<=n; i++)
    {
        int l,r;
        cin>>l>>r;
        ans+=(l-p)/a;
        p=l+r;
    }
    ans+=(m-p)/a;
    cout<<ans<<endl;
}