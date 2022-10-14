#include<bits/stdc++.h>
using namespace std;
int main(){
  int arr[3][3]={{1,1,1},{1,1,1},{1,1,1}};
  int inp[3][3];
  for(int i=0;i<3;i++){
      cin>>inp[i][0]>>inp[i][1]>>inp[i][2];
      inp[i][0]=inp[i][0]%2;
      inp[i][1]=inp[i][1]%2;
      inp[i][2]=inp[i][2]%2;

  }
if(inp[0][0]==1){
    arr[1][0]=0;
    arr[0][1]=0;
    arr[0][0]=0;
}
if(inp[0][1]==1){
    arr[0][0]=!arr[0][0];
    arr[1][1]=!arr[1][1];
    arr[0][2]=!arr[0][2];
    arr[0][1]=!arr[0][1];
}
if(inp[0][2]==1){
    arr[0][1]=!arr[0][1];
    arr[1][2]=!arr[1][2];
    arr[0][2]=!arr[0][2];
}
if(inp[1][0]==1){
    arr[1][0]=!arr[1][0];
    arr[0][0]=!arr[0][0];
    arr[2][0]=!arr[2][0];
    arr[1][1]=!arr[1][1];
}
if(inp[1][1]==1){
    arr[1][0]=!arr[1][0];
    arr[1][1]=!arr[1][1];
    arr[1][2]=!arr[1][2];
    arr[0][1]=!arr[0][1];
    arr[2][1]=!arr[2][1];
}
if(inp[1][2]==1){
    arr[1][2]=!arr[1][2];
    arr[1][1]=!arr[1][1];
    arr[0][2]=!arr[0][2];
    arr[2][2]=!arr[2][2];
}
if(inp[2][0]==1){
    arr[2][1]=!arr[2][1];
    arr[2][0]=!arr[2][0];
    arr[1][0]=!arr[1][0];
}
if(inp[2][1]==1){
    arr[2][1]=!arr[2][1];
    arr[1][1]=!arr[1][1];
    arr[2][0]=!arr[2][0];
    arr[2][2]=!arr[2][2];
}
if(inp[2][2]==1){
    arr[2][1]=!arr[2][1];
    arr[2][2]=!arr[2][2];
    arr[1][2]=!arr[1][2];
}
for(int i=0;i<3;i++){
    cout<<arr[i][0]<<arr[i][1]<<arr[i][2]<<endl;
}


}