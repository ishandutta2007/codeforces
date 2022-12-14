#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    if (n>=30)
        cout<<m<<endl;
    else
    {
        long long ret=1;
        while(n--)ret*=2;
        cout<<m%ret<<endl;
    }
}