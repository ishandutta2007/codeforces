#include<bits/stdc++.h>
using namespace std;
int main(){


  int n,m;
  cin >>n>>m;
  int ans;
  for(int i=n+1;;i++){
        int check=1;

      for(int j=2;j<=sqrt(i);j++){
          if(i%j==0){
            check=0;
            break;
          }
      
       
      }
       if(check==1){
      ans=i;
           break;
       }
  }
if(ans==m){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}





}