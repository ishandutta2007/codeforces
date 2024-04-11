#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    long long n,k;
    cin>>n>>k;
    n=min(n,k);
    long long r = n-(n==k);
    long long l = max(1LL,k-n);
    ll ret = max(r-l+1,0LL);
    if (ret%2)ret--;
    cout<<((ret)/2)<<endl;
}