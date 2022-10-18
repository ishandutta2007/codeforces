#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ss second
#define ff first
#define ld long double
#define mp make_pair

const int N = 2e5 + 11;

int a[N];

int main()
{
          ll n,m;
          cin>>n>>m;
          ll x=n+1,num=1;
          for (int i=1; i<=m; i++)
          {
                    ll l;
                    cin>>l;
                    if (n/x*x<n/l*l) {x=l; num=i;}
          }
          cout<<num<<" "<<n/x<<endl;
}