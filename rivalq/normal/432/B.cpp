//https://codeforces.com/contest/432/problem/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(int i=0;i<n;i++)
int main(){
    int n;
    cin>>n;
    int arr[n][2];
    lop(i,n) {cin>>arr[i][0]>>arr[i][1];}
    int ma=0,k;
    lop(i,n){
        ma=max(ma,max(arr[i][0],arr[i][1]));
    }
    int fr[ma+1]={0},h,a;
    lop(i,n) fr[arr[i][0]]++;
    lop(i,n){
        h=n-1+fr[arr[i][1]];
        a=2*(n-1)-h;
        cout<<h<<" "<<a<<"\n";
    }
    

}