#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int best[n]={0};
    for(int j=0;j<m;j++){
        int max=0;
        for(int i=0;i<n;i++){
           if(max<(int)arr[i][j]) max = (int) arr[i][j];
        }
        for(int i=0;i<n;i++){
            if((int)arr[i][j]==max) best[i]=1;
        }
    }
    int sum=0;
   for(int i=0;i<n;i++) sum+=best[i];
   cout<<sum<<endl;
}