#include<iostream>
using namespace std;
typedef __int64 ll;
int main()
{
    ll n,res=0;cin>>n;
    ll tmp=1;
    while(tmp<=n)
    {
        if((tmp&n)!=0) res++;
        tmp*=2;
    }
    cout<<res<<endl;
    return 0;
}