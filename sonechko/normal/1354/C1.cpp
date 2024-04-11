#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ld long double

const int N = 4e5 + 11;

void up()
{
    ld PI = 3.141592653589;
    ll n;
    cin>>n;
    n*=2;
    ld p=(ld)360/(ld)n;
    p/=(ld)2;
    p=(p*(ld)PI/(ld)180);
    ld a=0.5/tan(p);
    a*=2;
    cout.precision(10);
    cout<<fixed;
    cout<<a<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}