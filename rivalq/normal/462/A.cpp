#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n][n];
    for(int i=0;i<n;i++){
        for (int j = 0;j <n; j++)
        {
          cin>>arr[i][j];
        }
        
    }
  int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
         if(arr[i+1][j]=='o' && i!=n-1){
          c++;
         }
         if(arr[i-1][j]=='o' && i!=0){
          c++;
         }
         if(arr[i][j+1]=='o' && j!=n-1){
          c++;
         }
         if(arr[i][j-1]=='o' && j!=0){
          c++;
         }
         if(c%2){
             cout<<"NO"<<endl;
             return 0;
         }
         else{
             c=0;
         }
     }
}
    cout<<"YES"<<endl;
}