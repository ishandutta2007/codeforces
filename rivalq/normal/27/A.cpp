#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int t=1,c=1;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        if(arr[i]!=t){c=0; break;}
        else if(i<n-1 &&arr[i]!=arr[i+1])t++;
    }
    if(c==1) t++;
    cout<<t<<endl;
}