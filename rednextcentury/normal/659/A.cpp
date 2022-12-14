#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    a+=b;
    while(a<=0)
        a+=n;
    while(a>n)
        a-=n;
    cout<<a<<endl;
}