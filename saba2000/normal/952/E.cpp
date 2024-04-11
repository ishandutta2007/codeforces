#include<bits/stdc++.h>
using namespace std;
main(){
   int n;
   cin >> n;
   int x=0,y=0;
   for (int i=1;i <= n; i++){
       string a,b;
   cin >> a >> b;
   if(b == "hard")
    y++;
   else x++;
   }
   if(x < y) swap(x,y);
   for (int i = 1;i <= 100; i++){
       if((i*i+1)/2 >= x && i*i/2 >= y){ cout << i << endl; return 0;}
   }
}