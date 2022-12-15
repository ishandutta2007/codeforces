#include<iostream>

using namespace std;

unsigned long long log(unsigned long long p)
{
    if(p>1)
    {
        return 1+log(p>>1);
    }

    return 0;
}

int main ()
{
    unsigned long long l,r,a,b;

    ios::sync_with_stdio(false);

    cin>>l;

    //cout<<l<<endl;

    cin>>r;

    //cout<<r<<endl;

    if(l==r)
    {
        cout<<"0"<<endl;
        return 0;
    }
    a=log(l);
    b=log(r);
    //cout<<a<<" "<<b<<endl;

    while(a==b)
    {
    //cout<<a<<" "<<b<<endl;
        a=(unsigned long long)1<<a;
        //cout<<a<<endl;
        l-=a;
        r-=a;
        a=log(l);
        b=log(r);
    }

    //cout<<(1<<(b+1))<<endl;

    a=(unsigned long long)1<<(b+1);
    a--;

    cout<<a<<endl;

    return 0;
}