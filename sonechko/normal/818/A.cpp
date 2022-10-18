#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double
#define pb push_back
const int N = 2000 + 11;

ll s1[N][N],s2[N][N],a[N][N],use1[N][N],use2[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    cout<<n/2/(k+1)<<" "<<n/2/(k+1)*k<<" "<<n-n/2/(k+1)*(k+1)<<endl;
}