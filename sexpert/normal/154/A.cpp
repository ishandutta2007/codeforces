#include <bits/stdc++.h>
using namespace std;

vector<string> forb;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        forb.push_back(t);
    }
    int ans = 0, ct1, ct2;
    for(auto t : forb) {
        ct1 = ct2 = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[0] && s[i] != t[1]) {
                ans += min(ct1, ct2);
                ct1 = 0;
                ct2 = 0;
            }
            else {
                if(s[i] == t[0])
                    ct1++;
                else
                    ct2++;
            }
        }
        ans += min(ct1, ct2);
    }
    cout << ans << endl;
}