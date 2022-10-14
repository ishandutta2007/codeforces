#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    int n,m,t,l,r,pos=0,neg,k;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t==1) pos++; 
    }
    neg=n-pos;
    t=(neg<pos)?neg:pos;
    
   while(m--){
       cin>>l>>r;
       k=r-l+1;
       if(k&1){ cout<<"0\n";
       continue;}
       k/=2;
       if(k>t){
           cout<<"0\n";
           continue;
       }
       cout<<"1\n";
       
  }
}