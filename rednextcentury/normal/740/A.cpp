#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,b,c;
    cin>>n>>a>>b>>c;
    long long ret=(1LL<<55);
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            for (int k=0;k<10;k++)
            {
                long long m = n + i+2*j+3*k;
                if (m%4)continue;
                ret=min(ret,i*a+b*j+c*k);
            }
        }
    }
    cout<<ret<<endl;
}