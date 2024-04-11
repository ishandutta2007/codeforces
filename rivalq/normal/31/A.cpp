#include<bits/stdc++.h>
using namespace std;
int cb(vector<pair<int,int>> arr,int l,int u,int k){
    int mid;
    while(l<=u){
    mid=(l+u)/2;
    if(arr[mid].first==k){
        return mid;
    }
    else if(arr[mid].first>k){
        u=mid-1;
    }
    else{
        l=mid+1;
    }
    }
    return -1;
}
int main(){
    int n,l,u,k,in;
    cin>>n;
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++) {
        cin>>k;
        arr.push_back({k,i});
    }
    sort(arr.begin(),arr.end());
    for(int i=2;i<n;i++){
        for(int j=i-1;j>0;j--){
           l=0;
           u=j-1;
           k=arr[i].first-arr[j].first;
           in=cb(arr,l,u,k);
           if(in!=-1){
               cout<<arr[i].second+1<<" "<<arr[j].second+1<<" "<<arr[in].second+1<<endl;
               return 0;
           }
        }
    }
    cout<<-1<<endl;
}