#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int m = 0;
        int cnt = 0;
        long long ans = 0;
        for(int i = 0 ;i < s.size(); i++){
            if(s[i] == '+') cnt++;
        else cnt--;
            if(cnt < m) ans += i+1,
            cnt = m;
        }
        ans += s.size();
        cout<<ans<<endl;
    }
}