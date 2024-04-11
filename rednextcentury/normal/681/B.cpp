#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    for (int i=0;i<=1000;i++)
    {
        for (int j=0;j<=1000;j++)
        {
            long long x = i*1234567+j*123456;
            if (x>n)continue;
            long long y = n-x;
            if (y%1234==0)
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}