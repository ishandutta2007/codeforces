#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const ll N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    ll x1=0,y1=0;
    for (ll i=0; i<=n; i++)
        if ((n-i*a)>=0&&(n-i*a)%b==0)
        {
            x1=i;
            y1=(n-i*a)/b;
            break;
        }
    if (x1==0&&y1==0) {cout<<-1<<endl; return 0;}
    ll pos1=1;
    for (ll i=1; i<=x1; i++)
    {
        for (ll p=pos1; p<pos1+a-1; p++)
            cout<<p+1<<" ";
        cout<<pos1<<" ";
        pos1=pos1+a;
    }
    for (ll i=1; i<=y1; i++)
    {
        for (ll p=pos1; p<pos1+b-1; p++)
            cout<<p+1<<" ";
        cout<<pos1<<" ";
        pos1=pos1+b;
    }
    cout<<endl;
}