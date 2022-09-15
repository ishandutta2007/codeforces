#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    int a,s=0;
    cin>>a;
    for(int i=2;i<a;i++){
        int b=a;
        while(b){
            s+=b%i;
            b/=i;
        }
    }
    int g=gcd(s,(a-2));
    cout<<(s/g)<<'/'<<(a-2)/g;
    return 0;
}