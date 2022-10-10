#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    int milt = 0, malt = 0;
    bool tsk = false;
    for(int i = 0; i < s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z')
            milt++, malt++;
        else
            milt--;
        if(s[i] == '*')
            tsk = true;
    }
    if(milt > k) {
        cout << "Impossible\n";
        return 0;
    }
    if(malt < k) {
        if(!tsk) {
            cout << "Impossible\n";
            return 0;
        }
        bool fixed = false;
        string ans = "";
        for(int i = 0; i < s.size() - 1; i++) {
            if(s[i] == '?' || s[i] == '*')
                continue;
            if(s[i + 1] == '?')
                continue;
            if(s[i + 1] == '*' && fixed)
                continue;
            if(s[i + 1] == '*') {
                for(int j = 0; j < k - milt; j++)
                    ans += s[i];
                fixed = true;
            }
            else
                ans += s[i];
        }
        char c = s[s.size() - 1];
        if('a' <= c && c <= 'z')
            ans += c;
        cout << ans << endl;
        return 0;
    }
    int rem = malt - k;
    string ans = "";
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i] == '*' || s[i] == '?')
            continue;
        if(s[i + 1] == '*' || s[i + 1] == '?') {
            if(rem == 0)
                ans += s[i];
            else
                rem--;
            continue;
        }
        ans += s[i];
    }
    char c = s[s.size() - 1];
    if('a' <= c && c <= 'z')
        ans += c;
    cout << ans << endl;
    return 0;
}