#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][2];
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    int count=0;
    for(int i=0;i<n;i++){
        int lo=0,up=0,le=0,ri=0;
        for(int j=0;j<n;j++){
           if(arr[i][0]==arr[j][0] && arr[i][1]>arr[j][1]) lo=1;
           if(arr[i][0]==arr[j][0]&& arr[i][1]<arr[j][1])  up=1;
           if(arr[i][1]==arr[j][1] && arr[i][0]>arr[j][0]) le=1;
           if(arr[i][1]==arr[j][1] && arr[i][0]<arr[j][0]) ri=1;
        }
        if(lo&&up&&le&&ri){
            count++;
        }

    }
    cout<<count<<endl;
}