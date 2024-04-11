#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
#define ll long long
const int N = 4e5 + 11;
const int MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    n++;
    if (n==1) cout<<0<<endl; else
    if (n%2==0) cout<<n/2<<endl; else cout<<n<<endl;
}