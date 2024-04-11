#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a=5-k;
    int count=0;
    for(int i=0;i<n;i++){
    int t;
    cin>>t;
    if(t<=a){
        count++;
    }
    }
    cout<<count/3<<endl;
}