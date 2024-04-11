#include<bits/stdc++.h>
using namespace std;
const int N = 500000 + 11;
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
int main()
{
    sync;
    ll n,m;
    cin>>n>>m;
    if (m>n) m=n;
    if (m==n) {cout<<n<<endl; return 0;}
    ll l=1,r=2000000000;
    while (r-l>1)
    {
        ll mid=(l+r)/2;
        ll p=n-mid*(mid-1)/2;
        //cout<<mid+m<<" "<<p<<endl;
        if (p>mid+m) l=mid; else r=mid;
    }
    ll mid=l;
    ll p=n-mid*(mid-1)/2;
    //cout<<mid+m<<" "<<p<<endl;
    if (p>mid+m) cout<<r+m<<endl; else cout<<l+m<<endl;
}
/**
3 2

**/