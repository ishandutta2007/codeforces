#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main(){
    double d,h,v,e;cin>>d>>h>>v>>e;
    double pi=acos(-1.0);
    if(v<=pi*d*d*e/4) printf("NO\n");
    else{
        double ans=pi*d*d*h/(4*v-pi*d*d*e);
        cout.precision(5);
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}