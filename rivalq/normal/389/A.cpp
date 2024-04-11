#include<bits/stdc++.h>
using namespace std;
int min(int arr[],int n){
    int m=arr[0];
    for(int i=1;i<n;i++){
        if(m>arr[i]) m=arr[i];
    }
    return m;
}    
int notsame(int arr[],int n){
    int s=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]!=s) return 1;
    }
    return 0;
}    

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    while(notsame(arr,n)){
        int m =min(arr,n);
        for(int i=0;i<n;i++){
            if(arr[i]%m==0) arr[i]=m;
            else arr[i]=arr[i]%m;        
        }
    } 
    int sum=0;
    for(int i=0;i<n;i++) sum+=arr[i];
    cout<<sum<<endl;
}