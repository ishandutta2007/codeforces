#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast;
    long long l,r;
    cin>>l>>r;
    cout<<"YES"<<endl;
    for (long long i=l;i<=r;i+=2)
        cout<<i<<' '<<i+1<<endl;
}