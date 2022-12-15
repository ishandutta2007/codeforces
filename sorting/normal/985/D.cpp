#include<iostream>

using namespace std;

unsigned long long n,h;

unsigned long long binarySearch(unsigned long long x)
{
    unsigned long long l=1,r=2000000000,mid;

    while(l!=r)
    {
        mid=(l+r)/2;

        if(mid*(mid+1)/2<x)
            l=mid+1;
        else
            r=mid;
    }

    return l;
}

unsigned long long f(unsigned long long x)
{
    unsigned long long res=x*h;

    res+=(x/2)*(x/2-1);

    if(x%2==1)
        res+=x/2;

    return res;
}

unsigned long long binarySearch2(unsigned long long x)
{
    unsigned long long l=1,r=3000000000,mid;

    while(l!=r)
    {
        mid=(l+r)/2;

        if(f(mid)<x)
            l=mid+1;
        else
            r=mid;
    }

    return l;
}

int main ()
{
    unsigned long long p,p2;

    cin>>n>>h;

    p=binarySearch(n);

    //cout<<p<<endl;

    if(p>h)
    {
        p=h*(h-1)/2;
        p=n-p;
        //cout<<p<<endl;
        p2=binarySearch2(p);
        //cout<<p2<<endl;
        p2+=h-1;
        cout<<p2<<endl;
    }
    else
        cout<<p<<endl;

    return 0;
}