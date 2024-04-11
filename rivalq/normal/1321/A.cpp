//https://codeforces.com/contest/1321/problem/A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int r[n];
    int b[n];
    int a=0,c=0;
    for(int i=0;i<n;i++)cin>>r[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)r[i]-=b[i];
    for(int i=0;i<n;i++){
        if(r[i]==-1)a++;
        else if(r[i]==1)c++;
    }
    if(c==0){
        cout<<-1<<endl;
    }
    else{
        if(c>a)cout<<1<<endl;
        else{
             a++;
             int k=(a/c)+(a%c!=0);
             cout<<k<<endl;
        }
    }
}