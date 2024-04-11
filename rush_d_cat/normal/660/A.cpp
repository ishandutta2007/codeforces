#include<iostream>
using namespace std;
typedef __int64 ll;
ll a[1000+2];
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=m-1;i++){
        if(gcd(a[i],a[i+1])!=1) cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++){
        if(i==m){
            cout<<a[i]<<endl;
            break;
        }else{
            cout<<a[i]<<" ";
        }
        if(gcd(a[i],a[i+1])!=1){
            ll tmp=2;
            while(gcd(tmp,a[i])!=1||gcd(tmp,a[i+1])!=1){
                tmp++;
            }
            cout<<tmp<<" ";
        }
    }
    return 0;
}