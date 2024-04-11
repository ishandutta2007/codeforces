#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long x=1,sum=0,ret=0;
    while(n>0)
    {
        n-=x;
        x=x*2;
        ret++;
    }
    cout<<ret<<endl;
}