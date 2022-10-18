#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 11;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define ld long double
vector<ll> v;
int main()
{
    #ifdef LOCAL
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    sync;
    #endif // LOCAL
    ll n,k;
    cin>>n>>k;
    ll p=(ll)sqrt(n);
    for (ll i=1; i<=p; i++)
        if (n%i==0)
        {
            v.pb(i);
            if (i!=n/i) v.pb(n/i);
        }
    sort(v.begin(),v.end());
    if (v.size()<k) cout<<-1<<endl; else cout<<v[k-1]<<endl;
}