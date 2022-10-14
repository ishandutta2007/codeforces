
#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin >>n;
   int arr[n];
   int max=0;
   int maxi=0;
   for(int i=0;i<n;i++){
       int t;
       cin>>t;
       arr[i]=t;
       if(max<t){
           max=t;
           maxi=i;
       }
   }
int time=0;   
if(maxi!=0){
 for(int i=maxi;i>0;i--){
     arr[i]=arr[i]+arr[i-1]-(arr[i-1]=arr[i]);
     time++;
 }}
 int min=arr[n-1];
 int mini=n-1;
 for(int i=n;i>=0;i--){
   if(arr[i]<min){
       min=arr[i];
       mini=i;
   }
 }
 if(mini!=n-1){
     for(int i=mini;i<n-1;i++){
     arr[i+1]=arr[i]+arr[i+1]-(arr[i]=arr[i+1]);
     time++;
 }
 }
cout<<time<<endl;
}