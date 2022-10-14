#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        for(int i=0;i<n-1;i++){
            if(abs(arr[i+1]-arr[i])==1) {
                c=1;break;
            }
        }
        if(c) cout<<2<<endl;
        else cout<<1<<endl;
    }
}