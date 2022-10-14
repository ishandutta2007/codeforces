#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin>>n;
     int hm[n*(n-1)];
     int gm[n*(n-1)];
     int h[n],g[n];
     for(int i=0;i<n;i++){
         cin>>h[i]>>g[i];
     }
     int c=0;
     for(int j=0;j<n;j++){
         g[j]=g[0]+g[j]-(g[0]=g[j]);
         for(int k=1;k<n;k++){
            hm[c]=h[j];
            gm[c]=g[k];
            c++;
         }
    }
    int ans=0;
    for(int i=0;i<n*(n-1);i++){
        if(hm[i]==gm[i]){
           ans++;
        }
    }
    cout<<ans;
}