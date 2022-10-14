#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int visit[n+1]={0};
    for(int i=0;i<2;i++){
        int k;
        cin>>k;
        for(int j=0;j<k;j++){
            int t;
            cin>>t;
            visit[t]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            cout<<"Oh, my keyboard!"<<endl;
            return 0;
        }
    }
    cout<<"I become the guy."<<endl;

}