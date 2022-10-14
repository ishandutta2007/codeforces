#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n>=m){
     if(n%(2*m)==0)
     {
         cout<<n/2<<endl;
     }
     else
     {
         int k = n/(2*m)+1;
         cout<<m*k<<endl;
     }
     
    }
    else
    {
        cout<<-1<<endl;
    }
    
}