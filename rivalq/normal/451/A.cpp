#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,m;
     cin>>n>>m;
     if(n>m){
         m=n+m-(n=m);
     }
     if(n%2==0){
         cout<<"Malvika"<<endl;
     }
     else{
         cout<<"Akshat"<<endl;
     }
}