#include<bits/stdc++.h>
using namespace std;
int main(){

 int n;
 cin>>n;
 int arr[n][2];
 for(int i=0;i<n;i++){
     cin>>arr[i][0]>>arr[i][1];
 }
int l1=0,l0=0,r1=0,r0=0;
for(int i=0;i<n;i++){
int l=arr[i][0];
int r=arr[i][1];
if(l==1){
    l1++;
}
if(l==0){
    l0++;
}
if(r==0){
    r0++;
}
if(r==1){
r1++;}
}
int t=0;
if(l1>l0)
t=t+l0;
else
t=t+l1;
if(r1>r0)
t=t+r0;
else
t=t+r1;

cout<<t<<endl;
}