#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
   
    int c=0,bi=0,ba=0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(i%3==1){
            c+=t;
        }
        else if(i%3==2){
            bi+=t;
        }
        else{
            ba+=t;
        }
    }
    if(bi>c){
        if(bi>ba){
            cout<<"biceps";
        }
        else{
            cout<<"back";
        }
    }
    else{
        if(c>ba){
            cout<<"chest";
        }
        else{
            cout<<"back";
        }
    }
}