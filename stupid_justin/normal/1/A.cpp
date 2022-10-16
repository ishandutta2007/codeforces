#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,x;
    cin>>n>>m>>x;
    cout<<((n+x-1LL)/x)*((m+x-1LL)/x)<<endl;
}