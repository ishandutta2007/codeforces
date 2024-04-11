#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=0;
    for(int i=0;i<n-1;i++){
        if(max<(arr[i]-arr[i+1])){
            max=arr[i]-arr[i+1];
        }
    }
    if(max-c>0){
        cout<<max-c;
    }
    else{
        cout<<0;
    }
}