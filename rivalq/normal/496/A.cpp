#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   vector<int> arr(0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
   int mid=arr[2]-arr[0];
   int midi=1;
    for(int i=2;i<n-1;i++){
       if((arr[i+1]-arr[i-1])<mid){
           mid=arr[i+1]-arr[i-1];
           midi=i;
       }
    }
    arr.erase(arr.begin() + midi);
   int max=0;
   for(int i=1;i<n-1;i++){
       if(max<(arr[i]-arr[i-1])){
        
           max=arr[i]-arr[i-1];
       }
   }
   cout<<max<<endl; 

}