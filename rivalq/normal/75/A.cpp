#include<bits/stdc++.h>
using namespace std;
long long int rezo(long long n){
    long long int t=1;
    while((n/t)!=0){
        if(t==1 && n%10==0) n=n/10;
       else if((n/t)%10==0) n=n%t+(n/t)*(t/10);
       else   t*=10; 
    }
    return n;
}
int main(){
   long long int n1,n2;
   cin>>n1>>n2;
   long long int n3=n1+n2;
   if(rezo(n1)+rezo(n2)==rezo(n3)) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;
    
}