#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll w1,h1,w2,h2;
    cin>>w1>>h1>>w2>>h2;
    swap(w1,w2);
    swap(h1,h2);
    ///cout<<w2+2<<"+"<<h2*2<<"+"<<w2-w1<<"+"<<h1*2<<"+"<<w1+2<<endl;
    ll ans=w2+2+h2+h2+w2-w1+h1+h1+w1+2;
    cout<<ans<<endl;
}