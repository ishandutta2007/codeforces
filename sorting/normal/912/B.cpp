#include<iostream>
#include<cmath>

using namespace std;

const long long maxi=1000000000000000000;

long long logg(long long a)
{
    long long res=0;

    while(a>1)
    {
        a/=2;
        res++;
    }

    return res;
}

int main ()
{
    long long k,n,i,b;

    cin>>n>>k;

    b=(long long)logg(n);
    //cout<<((long long)1<<b)<<endl;

    long long res=(long long)pow(2,b+1)-1;

    if(k>=2)cout<<(long long)res<<endl;
    else cout<<n<<endl;

    return 0;
}