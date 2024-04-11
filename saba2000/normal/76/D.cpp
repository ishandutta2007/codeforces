#include<bits/stdc++.h>
#define ll long long
using namespace std;
main(){
   unsigned ll S,X,A,O;
   cin >>S >> X;
   A = S - X;
   if(A % 2){
        cout<<-1<<endl;
       return 0;
   }
   A /= 2;
   O = S - A;
   if(O < 0 || A < 0){
        cout <<-1<< endl;
        return 0;
   }
   unsigned ll x=0, y =0, z= 1;
   for(int i= 0; i < 64; i++){
        int a=0,o = 0;
        unsigned ll X = (z << i);
        if((z << i) & A) a = 1;
        if((z << i) & O) o = 1;
        if(a && !o) {
            cout<<-1<<endl;
           return 0;
        }
        if(a && o) x +=X, y += X;
        if(!a && o) y+=X;
   }
   cout<<x<<" "<<y<<endl;
}