#include<bits/stdc++.h>
using namespace std;



#define ll long long
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ull unsigned long long
#define mp make_pair
#define pb push_back



const int N = 1e5 + 11;
const ll MOD = 1e9 + 7;
#define mod %MOD


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    if (k==n||k==0) cout<<0<<" "; else cout<<1<<" ";
    if (k==0) cout<<0; else
    if (k<=n/3) cout<<k*2; else
    if (k<=n/3+n%3)
    {
        int ans=n/3*2;
        if (n%3==1) cout<<ans; else
        if (n%3==2) cout<<ans+2-(k-n/3);
    } else
    {
        k-=n%3;
        n=n/3*3;
        cout<<n-k;
    }
}