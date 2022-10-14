#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
          cout<<0<<" ";
        }
        cout<<k<<" ";
        for(int j=i+1;j<n;j++){
            cout<<0<<" ";
        }
        cout<<endl;

    }

}