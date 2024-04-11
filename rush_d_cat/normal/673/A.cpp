#include<iostream>
using namespace std;
int n,a[100];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=90;
    a[0]=0;
    int res=0;
    for(int i=0;i<=n;i++){
        if(a[i+1]-a[i]>15)
        {
            res=a[i]+15;
            break;
        }
        if(i==n-1) res=90;
    }
    cout<<res<<endl;
    return 0;
}