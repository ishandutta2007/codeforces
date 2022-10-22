#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        int n;
        cin>>n;
        map<int,int> mp;
        while(n--){
            int a;
            cin>>a;
            mp[a]++;
        }
        int ans=-1;
        for(int i=0;true;i++){
            if(mp[i]<2 && ans==-1)ans=i;
            if(mp[i]==0){
                cout<<ans+i<<endl;
                break;
            }
        }
    }
}