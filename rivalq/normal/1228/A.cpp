#include<bits/stdc++.h>
using namespace std;
int main(){

      int l,r;
      cin >>l>>r;
      for(int i=l;i<=r;i++){
          int t=1;
          int check=1;
       bool v[10]={false};
       while((i/t)!=0){
         if(v[(i/t)%10])
          { check=0;
          break;}
         v[(i/t)%10]=true;
           t=t*10;

       }
          if(check==1){
              cout<<i;
              return 0;
          }
          }
          cout<<-1;
          return 0;



}