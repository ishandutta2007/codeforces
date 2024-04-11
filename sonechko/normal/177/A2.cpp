#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
        int l;
        cin>>l;
        if (i==(n+1)/2||j==(n+1)/2||i==j||i+j==n+1) ans+=l;
    }
    cout<<ans<<endl;
}