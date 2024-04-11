#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
const int N = 1e3 + 11;

int main()
{
    ll n;
    cin>>n;
    ll a=2,b=3;
    int kol=2;
    if (n<=3) {cout<<n-1<<endl; return 0;}
    while (1==1)
    {
        ll c=a+b;
        if (c>n) {cout<<kol<<endl; return 0;}
        kol++;
        a=b;
        b=c;
    }
}