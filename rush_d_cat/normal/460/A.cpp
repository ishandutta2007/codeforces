#include<iostream>
using namespace std;
int main()
{
    int n,m;cin>>n>>m;
    int cnt=0,res=0;
    while(cnt!=n)
    {
        cnt++;res++;
        if(res%m==0) res++;
    }
    cout<<res<<endl;
}