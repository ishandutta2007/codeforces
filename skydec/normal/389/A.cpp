#include<iostream>
using namespace std;
long gcd(long a,long b)
{
     if(a%b==0)return b;else return gcd(b,a%b);
}
int main()
{
    long n;cin>>n;long ans;cin>>ans;
    for(long i=2;i<=n;i++){long k;cin>>k;ans=gcd(ans,k);}
    cout<<ans*n;
    //for(;;);
    return 0;
}