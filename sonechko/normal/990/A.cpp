#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll x=n/m;
    x*=m;
    ll res1=(n-x)*b;
    x=n/m;
    x++;
    x*=m;
    ll res2=(x-n)*a;
    cout<<min(res1,res2)<<endl;
}