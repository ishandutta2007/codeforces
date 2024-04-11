#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,time,te;
    cin>>n;
    int ca[n];
    for(int i=0;i<n;i++) cin>>ca[i];
    time=15*ca[0];
    for(int j=0;j<ca[0];j++){
        cin>>t;
        time+=t*5;
    }
    for(int i=1;i<n;i++){
        te=15*ca[i];
        for(int j=0;j<ca[i];j++){
             cin>>t;
             te+=5*t;
        }
        if(te<time) time=te;
    }
    cout<<time<<endl;
}