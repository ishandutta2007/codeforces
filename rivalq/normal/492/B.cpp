#include<bits/stdc++.h>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
int main(){
  int n,l;int m;
  cin>>n>>l;
  int arr[n];
    fr(i,n) cin>>arr[i];
    sort(arr,arr+n);
    
    m = 0;
    fr(i,n-1){
         if((arr[i+1]-arr[i])>m) m = (arr[i+1]-arr[i]);
     }
    if(arr[0]!=0) m= max(m,2*(arr[0]));
    if(arr[n-1]!=l) m = max(m,2*l-2*(arr[n-1]));
    cout<<m/2;
    if(m%2==1) cout<<".5000000000"<<endl;
    else cout<<endl;

}