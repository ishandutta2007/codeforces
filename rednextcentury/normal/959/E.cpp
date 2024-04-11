#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    n--;
    long long ret=0;
    for (long long i=0;i<60;i++)
    {
        long long x=(1LL<<i);
        if (x>n)break;
        ret+=((n-x)/(2*x) + 1)*x;
    }
    cout<<ret<<endl;
}