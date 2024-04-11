#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n,c=0,z1=0,z2=0,z3=0,z4=0,z5=0;
    cin>>n;
    int arr[n],ans[4]={-1,-1,-1,-1},is[3];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        if(arr[i]==0) z1=1;
       else if(arr[i]==100) z2=1;
       else if(arr[i]%10==0) {z3=1;is[0]=arr[i];}
       else if(arr[i]/10==0) {z4=1;is[1]=arr[i];}
       else {z5=1;is[2]=arr[i];}
    }
    if(z1==1){
    c++; ans[0]=0;
    }
    if(z2==1){
        c++;ans[1]=100;
    }
    if(z3==1){
        c++;ans[2]=is[0];
    }
    if(z4==1){
        c++;ans[3]=is[1];
    }
    if(z5==1 && z4==0 && z3==0){
        c++;ans[2]=is[2];
    }
    cout<<c<<endl;
    for(int i=0;i<4;i++){
        if(ans[i]!=-1) cout<<ans[i]<<" ";
    }
cout<<endl;
    

}