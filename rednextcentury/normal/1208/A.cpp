#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,n;
        cin>>a>>b>>n;
        n%=3;
        if (n==0)cout<<a<<endl;
        else if (n==1)cout<<b<<endl;
        else cout<<(a^b)<<endl;
    }
}