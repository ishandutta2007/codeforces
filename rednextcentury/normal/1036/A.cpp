#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,k;
    cin>>n>>k;
    cout<<k/n+(k%n>0)<<endl;
}