#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z,t1,t2,t3;
    cin>>x>>y>>z>>t1>>t2>>t3;
    int te=t2*(abs(x-z)+abs(x-y))+3*t3;
    int ts=abs(x-y)*t1;
    if(ts>=te){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    } 
}