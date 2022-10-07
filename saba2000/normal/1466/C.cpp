#include<bits/stdc++.h>
using namespace std;
int x[100009];
main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 1; i <s.size(); i++){
            if(s[i] == s[i-1] || (i > 1 && s[i] == s[i-2])) s[i] = '?',ans++;
        }
        cout<<ans<<endl;
    }

}