#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,t,ct;
    vector<int>d(100000,0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        ct=t;
        for (int j=2;j<400;j++){
            if(ct%j==0){
                d[j]++;
                while(ct%j==0){ct/=j;}
            }
        }
        if(ct>1){d[ct]++;}
    }
    int ans=1;
    for(int i=0;i<100000;i++){
        if (d[i]>ans){
            ans=d[i];
        }
    }
    cout<<ans;
}