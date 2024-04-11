#include <bits/stdc++.h>

using namespace std;
long long a[1000000];
int main()
{
    long long ret=0;
    int b,k;
    cin>>b>>k;
    while(k--)
    {
        long long x;
        cin>>x;
        ret=ret*b+x;
        ret%=2;
    }
    if (ret%2)cout<<"odd"<<endl;
    else cout<<"even"<<endl;
    return 0;
}