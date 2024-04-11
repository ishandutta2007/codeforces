#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
int main(){
    ll a[100000+2];int n;cin>>n;
    ll sum=0,m=-1;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        if(a[i]>m) m=a[i];
        sum+=a[i];
    }
    cout<<2*m-sum+1<<endl;
    return 0;
}