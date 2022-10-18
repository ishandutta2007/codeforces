#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

int a[N];

int main()
{
    int q;
    cin>>q;
    while (q--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        if (b<a*2) cout<<(n/2)*b+(n%2)*a<<"\n";
        else cout<<n*a<<"\n";
    }
}