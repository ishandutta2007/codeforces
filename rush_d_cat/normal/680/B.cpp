#include<iostream>
#include<cstdio>
using namespace std;
int a[101];
int main()
{
    int n,b,res=0;cin>>n>>b;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if((2*b-i<1)||(2*b-i>n)) res+=a[i];
        else if(a[2*b-i]+a[i]==2) res++;
    }
    cout<<res<<endl;
    return 0;
}