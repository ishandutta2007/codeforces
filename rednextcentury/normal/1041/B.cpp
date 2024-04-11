#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
using namespace std;
int a[1000000];
int main ()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long a,b,x,y;
    cin>>a>>b>>x>>y;
    long long g=__gcd(x,y);
    x/=g;
    y/=g;
    cout<<min(a/x,b/y)<<endl;
}