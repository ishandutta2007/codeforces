#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,n;
    cin>>s>>n;
    int ds[n],bo[n];
    for(int i=0;i<n;i++){
        cin>>ds[i]>>bo[i];
    }
    int kill[n]={0};
    for(int i=0;i<n;i++){
       
        for(int j=0;j<n;j++){
            if(s>ds[j] && !(kill[j])==1){
                kill[j]=1;
                s=s+bo[j];
                }
        }
      }
    for(int i=0;i<n;i++){
        if(kill[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}