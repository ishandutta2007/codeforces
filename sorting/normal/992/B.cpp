#include<iostream>

using namespace std;

long long gcd(long long a,long long b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int main ()
{
    long long x,y,i,l,r,res=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>l>>r>>x>>y;


    for(i=x;i*i<=x*y;i+=x)
        if(x*y%i==0 && i>=l && i<=r && x*y/i>=l && x*y/i<=r && gcd(i,x*y/i)==x)
        {
            //cout<<i<<endl;
            if(i*i==x*y)
                res++;
            else
                res+=2;
        }

    cout<<res<<endl;

    return 0;
}