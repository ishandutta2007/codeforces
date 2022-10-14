//https://codeforces.com/contest/265/problem/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n,a)     for(int i=0;i<n;i+=a)
int main(){
    ios_base::sync_with_stdio(0);
    int n,t=0,h=0;
    cin>>n;int arr[n];
    lop(i,n,1) cin>>arr[i];
    lop(i,n,1){
           t+=abs(arr[i]-h)+1;h=arr[i];
        }
        t+=n-1;
        cout<<t<<"\n";

}