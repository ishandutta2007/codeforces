#include<iostream>
using namespace std;
int main(){
    unsigned long long int n;
    unsigned long long int k;
    cin>>n>>k;
   if (n%2==0){
       if(k<=n/2){
           cout<<1+2*(k-1)<<endl;
       }
       else{
           k=k-n/2;
           cout<< 2+2*(k-1)<<endl;
       }
       
   }
   else{
       if (k<=(n+1)/2){
           cout<<1+2*(k-1)<<endl;

       }
       else{
           k = k-(n+1)/2;
           cout<<2+2*(k-1);
       }
   }
    return 0;
}