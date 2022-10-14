#include<bits/stdc++.h>
using namespace std;
int fr(int arr[],int k,int n){
    int c=0;
    for(int i=0;i<n;i++){
        if(k==arr[i]) c++;
    }
    return c;
}
int main(){
    int n,t;
   
    cin>>n;
     int d =(n%2==0)?n/2:n/2+1;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>t; arr[i]=t;
       
    }

for(int i=0;i<n;i++){
    if(fr(arr,arr[i],n)>d){
        cout<<"NO"<<endl;
        return 0;
    }
}    
cout<<"YES"<<endl;
return 0;}