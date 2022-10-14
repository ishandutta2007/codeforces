#include<bits/stdc++.h>
using namespace std;
int main(){
    int p,c=0;
    cin>>p;
    int n=p-1;
    int xmodp[p];
    xmodp[0]=0;
    for(int x=1;x<p;x++){
      xmodp[1]=x;
      for(int i=2;i<p;i++){
        if(i&1) xmodp[i]=(xmodp[(i-1)/2]*xmodp[(i+1)/2])%p;
        else xmodp[i]=(xmodp[i/2]*xmodp[i/2])%p;
      }
      if((xmodp[p-1]+p-1)%p==0){
          int b=1;
          for(int i=1;i<p-1;i++){
              if((xmodp[i]+p-1)%p==0) {
                  b=0;
                  break;
              }
             
          }
           if(b==1) c++;
      }

    } 
    cout<<c<<endl; 
}