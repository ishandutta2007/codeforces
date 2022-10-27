#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int cnt1[367],cnt2[367];
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    for(int i=1;i<=n;i++){
        char a;cin>>a;
        int s,t;cin>>s>>t;
        if(a=='F'){
            for(int j=s;j<=t;j++) cnt1[j]++;
        }
        if(a=='M'){
            for(int j=s;j<=t;j++) cnt2[j]++;
        }
    }
    int m=0;
    for(int i=1;i<=366;i++){
        m=max(m,min(cnt1[i],cnt2[i]));
    }
    cout<<2*m<<endl;
    return 0;
}