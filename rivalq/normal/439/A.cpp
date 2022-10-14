#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int sum=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        sum=sum+t;
    }
if(sum+10*(n-1)>d){
    cout<<-1<<endl;
    return 0;
}    
else{
    cout<<(d-sum)/5<<endl;
}}