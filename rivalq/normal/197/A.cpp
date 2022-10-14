#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,r,mi;
    cin>>a>>b>>r;
    mi=min(a,b);
    if(2*r<=mi){
       cout<<"First\n";
    }
    else{
        cout<<"Second\n";
    }
}