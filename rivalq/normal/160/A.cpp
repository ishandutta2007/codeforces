#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
  sort(arr,arr+n);
  int sum=0;
   for(int i=0;i<n;i++)
   {
       sum=sum+arr[i];
   }
   int s=0;
   int c=0;
  for(int i=n-1;i>=0;i--){
     c=c+arr[i];
     s++;
     if(c*2>sum){
         break;
     }
  }
  cout<<s;

}