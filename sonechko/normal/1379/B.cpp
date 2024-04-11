#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;
const ll MOD = 1e9 + 7;

void up()
{
    ll l,r,m;
    cin>>l>>r>>m;
    for (int a=l; a<=r; a++)
    {
        ll n=m/a;
        ll bc=m-n*1ll*a;
        if (n!=0&&bc<=r-l) {cout<<a<<" "<<r<<" "<<r-bc<<"\n"; return;}
        n++;
        bc=m-n*1ll*a;
        if (-bc<=r-l) {cout<<a<<" "<<l<<" "<<l-bc<<"\n"; return;}
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        up();
    }
}