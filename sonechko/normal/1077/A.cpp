#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e6 + 11;
const int MOD = 998244353;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
          ll a,b,k;
          cin>>a>>b>>k;
          cout<<a*((k+1)/2)-b*(k/2)<<"\n";
    }
}