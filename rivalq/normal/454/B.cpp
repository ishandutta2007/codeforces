//https://codeforces.com/contest/454/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n==2){
        if(arr[0]>arr[1]) cout<<1<<"\n";
        else cout<<"0\n";
        return 0;
    }
    int in=-1;
    for(int j=0;j<n-1;j++){
         if(arr[j]>arr[j+1]){
            in=j;break;
        }
    }
    if(in==-1){cout<<"0\n";return 0;}
    int c=1;
    for(int i=in+1;i<n-1;i++){
        if(arr[i]>arr[i+1]){c=0;break;}
    }
    if(c==0){
     cout<<"-1\n";
    }
    else {
        if(arr[n-1]<=arr[0]) cout<<n-in-1<<"\n";
        else cout<<"-1\n";
    }


}