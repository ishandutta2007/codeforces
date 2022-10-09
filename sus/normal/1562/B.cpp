#include<bits/stdc++.h>
using namespace std;
int t,k;
string s,u[17]={"1","4","6","8","9","22","25","27","32","33","35","52","55","57","72","75","77"};
void solve(){
    for(int i=0;i<17;i++){
        int l=0;
        for(int j=0;j<k;j++){
            if(s[j]==u[i][l])l++;
        }
        if(l==u[i].size()){cout<<l<<endl<<u[i];return;}
    }
}
int main(){
    for(cin>>t;t--;cout<<endl){
        cin>>k>>s;
        solve();
    }
    return 0;
}