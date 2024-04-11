#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n][2];
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    int max=(k>arr[0][1])?arr[0][0]:(arr[0][0]-arr[0][1]+k);
    for(int i=1;i<n;i++){
       if(k<arr[i][1]){
           max=(max>(arr[i][0]-arr[i][1]+k))?max:arr[i][0]-arr[i][1]+k;
       }
       else{
           max=(max>arr[i][0])?max:arr[i][0];
       }
    }
    cout<<max;
   
}