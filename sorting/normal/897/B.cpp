#include<iostream>

using namespace std;

long long p;

long long pal(long long n)
{
    int l=0,t=n,st=1,i,rev=0;

    while(t>=10)
    {
        l++;
        rev=rev*10+(t%10);
        st*=10;
        t/=10;
    }
    rev=rev*10+(t%10);
    l++;
    st*=10;

    return n*st+rev;
}

int main ()
{
    long long k,sum=0;

    cin>>k>>p;

    for(int i=1;i<=k;i++)
    {
        sum+=pal(i);
        sum%=p;
    }

    cout<<sum<<endl;

    return 0;
}