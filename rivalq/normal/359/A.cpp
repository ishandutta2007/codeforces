#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,t,c=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>t;
            if((i==0 || i==n-1 || j==0 || j==m-1) && t==1) c=1;
        }
    }
    if(c==1) cout<<2<<endl;
    else cout<<4<<endl;
}