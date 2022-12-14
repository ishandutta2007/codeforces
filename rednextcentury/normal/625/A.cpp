#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n,a,b,c;
    cin>>n>>a>>b>>c;
    if (a<b-c || n<c)cout<<n/a<<endl;
    else
    {
        n-=c;
        long long ret=n/(b-c);
        n=n%(b-c);
        n+=c;
        ret+=n/a;
        cout<<ret<<endl;
    }
}