#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 3000 + 11;
const int MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ld ans=0;
    for (int i=1; i<=n; i++)
        ans+=(ld)1/(ld)i;
    cout.precision(6);
    cout<<fixed;
    cout<<ans;
}