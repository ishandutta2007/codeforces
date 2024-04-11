#include<bits/stdc++.h>
using namespace std;
int main(){
int sum=0,row,column;
   int arr[5][5];
   for (int i=0;i<5;i++){
       cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3]>>arr[i][4];
       
   }
  for (int j=0;j<5;j++){
      sum=arr[j][0] + arr[j][1]+arr[j][2]+arr[j][3]+arr[j][4];
      if(sum==1){
          row =j;
          break;
      }
  }
  
  for (int k=0;k<5;k++){
      if (arr[row][k]==1){
          column=k;
          break;
      }
  }
  
  cout<< abs(2-row)+abs(2-column)<<endl;
return 0;
 
}