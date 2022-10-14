#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    sort(arr,arr+m);
    int min=arr[n-1]-arr[0];
    for(int i=0;i<=(m-n);i++){
     int t= arr[n-1+i]-arr[i];
    if(min> t){
        min =t;
    }}
    cout<<min<<endl;
}