#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define ld long double

const int N = 1e6 + 11;



int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    while (1==1)
{
          ll x=a/(2*b);
          a-=x*(2*b);
          if (a==0||b==0) {cout<<a<<" "<<b<<endl; return 0;}
          ll y=b/(2*a);
          b-=y*(2*a);
          if (a==0||b==0||y==0) break;
}
cout<<a<<" "<<b<<endl;
}