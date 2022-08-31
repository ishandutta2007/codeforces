#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        string r = "";
        r += s[0];
        for (int i = 1; i < s.size(); i+=2)
            r += s[i];
        cout<<r<<endl;
    }

    return 0;
}