#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
 cin>>n;
 int arr[n][2];
 for(int i=0;i<n;i++){
     cin>>arr[i][0]>>arr[i][1];
 }
 //arr[i][0]-->exit
 //arr[i][i]-->entry
int p=0;
int m=0;
for(int i=0;i<n;i++){
    int exit=arr[i][0];
    int entry=arr[i][1];
    p =p+ entry-exit;
    if(m<p){
        m=p;
    }
}
cout<<m<<endl;

}