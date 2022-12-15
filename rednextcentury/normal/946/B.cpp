#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b;
    cin>>a>>b;
    while(1)
    {
        assert(a>=0 && b>=0);
        if (a==0 || b==0)break;
        if (a>=2*b)
        {
            long long need=(a-2*b)/(2*b)+1;
            a-=need*2*b;
        }
        else if (b>=2*a)
        {
            long long need=(b-2*a)/(2*a)+1;
            b-=need*2*a;
        }
        else
            break;
    }
    cout<<a<<' '<<b<<endl;
}