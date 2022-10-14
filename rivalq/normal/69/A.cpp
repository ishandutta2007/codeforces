#include<bits/stdc++.h>
using namespace std;
int main(){
    
       int n,sumx=0,sumy=0,sumz=0;
       cin >> n;
       int arr[n][3];
       for(int i=0;i<n;i++){
           cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
       }
    
       for(int j=0;j<n;j++){
         sumx =sumx+arr[j][0];
         sumy= sumy+arr[j][1];
         sumz=sumz+arr[j][2];
         
       }
      if(sumx==0&&sumy==0&sumz==0){
           
           cout<<"YES"<<endl;
            }
       else{
           cout<<"NO"<<endl;
       }
           
          
    
    
    for(int k=0;k<n;k++){
       
    }
    
    
    return 0;
    }