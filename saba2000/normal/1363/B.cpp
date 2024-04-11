#include<bits/stdc++.h>
using namespace std;
int p[1009];
main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin >> s;
        for(int i = 1; i <= s.size(); i++){
            p[i] = p[i-1];
            if(s[i-1] == '1') p[i]++;
        }
        int ans = s.size();
        int n = s.size();
        for(int i = 0; i <= n; i++){
            int A = p[i], B = p[n] - p[i];
            ans = min(ans, A + (n - i - B));
            ans = min(ans, B + i - A);
        }
        cout<<ans<<endl;
    }

}