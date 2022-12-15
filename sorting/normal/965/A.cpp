#include<iostream>

using namespace std;

int main ()
{
    int k,n,s,p,res;

    cin>>k>>n>>s>>p;

    res=n/s;
    if(n%s)res++;
    res*=k;
    n=res;
    res=n/p;
    if(n%p)res++;


    cout<<res<<endl;

    return 0;
}