#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    long long n,k,a,b;
    cin>>n>>k>>a>>b;
    if (k==1)
    {
        cout<<(n-1)*a<<endl;
    }
    else
    {
        long long ret=0;
        while(n>1)
        {
            if (n%k==0)
            {
                ret+=min((n-n/k)*a,b);
                n/=k;
            }
            else
                ret+=min(n%k,n-1)*a,n=n-n%k;
        }
        cout<<ret<<endl;
    }
}