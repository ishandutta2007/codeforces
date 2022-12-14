#include<stdio.h>
# include <bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b)
{
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
int main()
{
    long long l,r;
    cin>>l>>r;
    for (long long a=l;a<=r;a++)
    {
        for (long long b=a+1;b<=r;b++)
        {
            if (GCD(a,b)>1)continue;
            for (long long c=b+1;c<=r;c++)
            {
                if (GCD(b,c)==1 && GCD(a,c)!=1)
                {
                    cout<<a<<' '<<b<<' '<<c<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<-1<<endl;
}