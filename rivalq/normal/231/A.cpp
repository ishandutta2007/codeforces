#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 int count=0;
 for(int i=0;i<n;i++){
     int t1,t2,t3;
     cin>>t1>>t2>>t3;
     if((t1+t2+t3)>1)
     count++;
 }
cout<<count<<endl;
}