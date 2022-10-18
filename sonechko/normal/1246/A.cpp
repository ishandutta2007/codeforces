#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long

const int N = 4e5 + 11;

bool good(ll n, ll kol)
{
    if (n<0) return false;
    if (kol>n) return false;
    ll p=0;
    for (int j=0; j<60; j++)
        if (n&(1ll<<j)) p++;
    if (kol<p) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
    ll n,p;
    cin>>n>>p;
    for (int j=1; j<=1000000; j++)
        if (good(n-p*j,j)) return cout<<j,0;
    cout<<-1;
}
/**
x=2^p1+2^p2+2^p3+...+k*p
(x-k*p) = 2^p_1+2^p_2+...2^p_k

11


**/