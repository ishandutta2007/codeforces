#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  int arr[4];
  multimap<int,int> m;
 for(int i=0;i<4;i++){
     int t;
     cin>>t;
     m.insert({t,t});
     arr[i]=t;
}
float n=0;
for(int i=0;i<4;i++){
if(m.count(arr[i])==2)
n=n+0.5;
if(m.count(arr[i])==3)
n=2;
if(m.count(arr[i])==4)
n=3;
}
int j=n;
cout<<j<<endl;
}