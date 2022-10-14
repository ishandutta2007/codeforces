#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,v;
    cin>>n>>v;
    int count=0;
    int visit[n+1]={0};
    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int t;
            cin>>t;
            if(v>t&&visit[i+1]==0){
                count++;
              visit[i+1]=1;
            }
        }
    }
  cout<<count<<endl;
 for(int i=1;i<n+1;i++){
     if(visit[i]==1){
         cout<<i<<" ";
     }
 }
}