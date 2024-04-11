//https://codeforces.com/problemset/problem/279/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n,a)     for(int i=0;i<n;i+=a)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t;cin>>n>>t;
    int arr[n];int f=0;
    lop(i,n,1) cin>>arr[i];
    lop(i,n,1){
        if(arr[i]<=t) {f=1;break;}
    }
    if(!f) {cout<<0;return 0;}
    int ans=0;
    lop(i,n,1) ans+=arr[i];
    int te[n]={0};te[0]=ans-arr[0];
    lop(i,n,1){
        te[i]=te[i-1]-arr[i];
    }
    int ma=1,l=0,u=n-1;
    for(int i=0;i<n-1;i++){
        l=i;u=n-1;int mid,ans;
        while(l<=u){
            mid=(l+u)/2;

            if(arr[i]+te[i]-te[mid]<=t) {l=mid+1;ans=mid;}
            else u=mid-1;
        }
      ma=max(ma,ans-i+1);

        
    }
    cout<<ma<<endl;

    

}