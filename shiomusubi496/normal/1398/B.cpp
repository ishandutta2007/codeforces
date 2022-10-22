#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int Q;
    cin>>Q;
    while(Q--){
        string S;
        cin>>S;
        S+='0';
        vector<int> A;
        int cnt=0;
        for(char c:S){
            if(c=='0'){
                A.push_back(cnt);
                cnt=0;
            }else cnt++;
        }
        sort(A.rbegin(),A.rend());
        int ans=0;
        for(int i=0;i<A.size();i+=2)ans+=A[i];
        cout<<ans<<endl;
    }
}