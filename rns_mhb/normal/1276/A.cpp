#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t --) {
        string s;
        cin >> s;
        int n = s.length();
        vector <int> ans;
        for(int i = 0; i < n; i ++) if(s[i] == 'o') {
            if(i+2 < n && s[i+1] == 'n' && s[i+2] == 'e') {
                if(i-2 >= 0 && s[i-1] == 'w' && s[i-2] == 't') ans.push_back(i+1);
                else ans.push_back(i+2);
            }
            else if(i-2 >= 0 && s[i-1] == 'w' && s[i-2] == 't') ans.push_back(i);
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
        cout << endl;
    }
}