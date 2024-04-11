#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long x=0;
    long long i=1;
    while(x+i < n)
        x+=i,i++;
    cout<<n-x<<endl;
}