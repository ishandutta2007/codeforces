#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n,k;
    cin>>n>>k;
    cout<<k*(n/k+1)<<endl;
    return 0;
}