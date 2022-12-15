#include<iostream>

using namespace std;

bool check(long long n,long long k)
{
    long long res=0,n2=n;

    while(n>0)
    {
        if(n>=k)
        {
            res+=k;
            n-=k;
        }
        else
        {
            res+=n;
            n=0;
        }

        n-=n/10;
    }

    //cout<<res<<" "<<k<<endl;

    if(res*2>=n2)
        return 1;

    return 0;
}

int main ()
{
    long long l,r,n,mid;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    l=1;
    r=n;

    while(l!=r)
    {
        mid=(l+r)/2;

        //cout<<l<<" "<<r<<endl;
        //cout<<n<<endl;

        if(check(n,mid))
            r=mid;
        else
            l=mid+1;
    }

    cout<<l<<"\n";

    return 0;
}