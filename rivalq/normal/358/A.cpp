#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,l,u,mi,ma;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n-1;j++){
            l=min(arr[i],arr[i+1]);u=arr[i]+arr[i+1]-l;
            mi=min(arr[j],arr[j+1]);ma = arr[j]+arr[j+1]-mi;
            if((mi<l && l<ma && u>ma) || (l<mi && mi<u && u<ma)) {cout<<"yes"<<endl; return 0;}
        }
    }
    cout<<"no"<<endl;
    return 0;
}