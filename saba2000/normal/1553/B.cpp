#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s,t;
        cin >> s>>t;
        int Ok = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size() && j - i < t.size(); j++){
                if(s[j] != t[j-i]) break;
                int ok = 1;
                for(int k = j - i + 1; k < t.size(); k++){
                    if(2*(j-i)-k+i < 0 || t[k] != s[2*(j-i)-k+i]) {ok = 0; break;}
                }
                if(ok) Ok = 1;
            }
        }
        if(Ok) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }

}