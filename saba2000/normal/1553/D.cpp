#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int x = (s.size() +  t.size()) % 2, j = 0;
        while(j < t.size() && x < s.size()){
            while(x < s.size() && s[x] != t[j]) x += 2;
            if(x < s.size()) j++,x++;
        }
        if(j == t.size()){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
 
}