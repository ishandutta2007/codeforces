#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ss second
#define ff first
#define ll long long
#define ld long double
#define endl "\n"
#define mp make_pair

const ll N = 2e5 + 11;

int use[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    if (n==1&&k<=2) {cout<<"YES"<<endl; return 0;} else
    if (n==1) {cout<<"NO"<<endl; return 0;}
    if (k==1) {cout<<"YES"<<endl; return 0;}
    if (k>=n) {cout<<"NO"<<endl; return 0;}
    if (k>=100000) {cout<<"NO"<<endl; return 0;}
    for (int x=1; x<=min(100000ll,k); x++)
    {
        if (use[n%x]==1) {cout<<"NO"<<endl; return 0;}
        use[n%x]=1;
    }
    cout<<"YES"<<endl;
}