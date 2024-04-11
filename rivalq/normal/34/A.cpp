#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int mi=abs(arr[0]-arr[1]);
    int i1=0,i2=1;
    for(int i=1;i<n-1;i++){
      if(mi>(abs(arr[i]-arr[i+1]))) {
          mi=abs(arr[i]-arr[i+1]);
          i1=i;i2=i+1;
      }
    }
    if(mi>abs(arr[0]-arr[n-1])){
        i1=0;i2=n-1;
    }
    i1++;i2++;
    cout<<i1<<" "<<i2<<endl;
}