#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main()
{
    int n, i, j, x, b, c;
    cin>>x>>b>>c>>n;
    if(x>=n||b<c||c>=n||x+b<c||b>=n||x+b-c>=n||x<c) cout<<"-1";
    else cout<<n-x-b+c;

}