#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,l,u,lt,ut;
    cin>>n>>l>>u;
    n--;
    int arr[100]={0};
    for(int i=l;i<u;i++){
        arr[i]=1;
    }
    for(int i=0;i<n;i++){
        cin>>lt>>ut;
        if(lt<l) lt=l;
        if(ut>u) ut=u;
        for(int j=lt;j<ut;j++) arr[j]=0;; 
    }
   
    int c=0;
    for(int i=0;i<100;i++){
        if(arr[i]==1) c++;
    }

   cout<<c<<endl;
}