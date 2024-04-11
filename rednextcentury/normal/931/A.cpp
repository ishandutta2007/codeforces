#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int a,b;
    cin>>a>>b;
    if (a>b)swap(a,b);
    int l = (b-a)/2;
    int r = (b-a)/2+(b-a)%2;
    cout<<l*(l+1)/2+r*(r+1)/2<<endl;
}