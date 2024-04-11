#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,b;
    cin>>m>>b;
    long long x=m*b;
    long long ret=0;
    for (long long i=0;i<=x;i++)
    {
        long long y=(x-i)/m;
        long long cur=y*(y+1)/2;
        cur=(cur*(i+1))+(y+1)*i*(i+1)/2;
        ret=max(ret,cur);
    }
    cout<<ret<<endl;
}