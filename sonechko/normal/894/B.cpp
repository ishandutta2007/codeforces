#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ss second
#define ff first
const int MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;
ll p(ll d, ll r)
{
    if (r==0) return 1;
    if (r%2==1) return (p(d,r-1)*d)mod;
    ll pp=p(d,r/2);
    return (pp*pp)mod;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    if (n>m) swap(n,m);
    if (n==1&&k==1) {cout<<1<<endl; return 0;} else
    if (n==1&&m%2==1) {cout<<1<<endl; return 0;} else
    if (n==1) {cout<<0<<endl; return 0;}
    if (n%2==0&&m%2!=0&&k==-1) {cout<<0<<endl; return 0;}
    if (n%2==1&&m%2==0&&k==-1) {cout<<0<<endl; return 0;}
    ll res1=p(2,n-1);
    cout<<p(res1,m-1)<<endl;
}
//
/**
2 2 - 2
2 3 - 4
2 4 - 8
2 5 - 16
..
3 3 - 16 2  4
3 4 - 64 2  6
3 5 - 256 2  8
..
4 4 - 512 2  9
4 5 - 4096 - 2  12

5 5 - 65536 - 2  16
**/