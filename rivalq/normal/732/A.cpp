#include<iostream>
using namespace std;
int main(){
  int k,r,i=1;
  cin>>k>>r;
  while(-1){
      if((k*i-r)%10==0 || k*i%10==0){
        break;
      }
      else{
          i++;
      }
  }
  cout<<i;


}