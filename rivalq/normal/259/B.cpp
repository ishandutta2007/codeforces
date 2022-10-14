//https://codeforces.com/contest/259/problem/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(int i=0;i<n;i++)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int arr[3][3],sum;
    lop(i,3) lop(j,3) cin>>arr[i][j];
    for(int i=1;i<=100000;i++){
       arr[1][1]=i;
       sum=arr[1][1]+arr[1][0]+arr[1][2];
       arr[0][0]=sum-arr[0][1]-arr[0][2];
       arr[2][2]=sum-arr[2][0]-arr[2][1];
       if(arr[2][2]>0&&arr[0][0]>0 && (arr[0][0]+arr[1][1]+arr[2][2])==sum) break;
    }
    lop(i,3) {lop(j,3) cout<<arr[i][j]<<" ";cout<<"\n";}
}