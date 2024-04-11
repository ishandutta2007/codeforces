#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 1e6 + 11;

ll a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll x,y;
    cin>>x>>y;
    char h='1';
    ll kol=0;
    for (int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if (ch!=h)
        {
            h=ch;
            if (ch=='0') kol++;
        }
    }
    if (kol==0) cout<<0<<endl; else cout<<min(x,y)*(kol-1)+y<<endl;
}