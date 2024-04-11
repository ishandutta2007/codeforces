#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 4e5 + 11;

void up()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b>=a) cout<<b<<"\n"; else
    {
        a-=b;
        if (c<=d) cout<<"-1\n"; else
        {
            ll kol=c-d;
            ll p=(a+kol-1)/kol;
            cout<<b+p*c<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}