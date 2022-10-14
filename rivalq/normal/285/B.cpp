//https://codeforces.com/problemset/problem/285/B
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n,a)     for(int i=0;i<n;i+=a)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     int n,s,t,p;
     cin>>n>>s>>t;
     int arr[n],visit[n]={0};
     lop(i,n,1) cin>>arr[i];
     lop(i,n,1) {if(arr[i]==s)p=i;}
     int x=0;
     while(1){
        if(arr[p]==t) break;
       else if(arr[p]==p+1) {x=-1;break;}
       else{
          if(visit[p]) {x=-1;break;}
          visit[p]=1;
          p=arr[p]-1;x++;
       }
}
cout<<x<<"\n"; 
}