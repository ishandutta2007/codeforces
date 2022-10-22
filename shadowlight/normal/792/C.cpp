#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    vector <int> cnt(3, 0);
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        cnt[x % 3]++;
        sum += x % 3;
    }
    if (sum % 3 == 0) {
        cout << s;
        return 0;
    }
    if (!cnt[1]) {
        if (cnt[2] < 3 && !cnt[0]) {
            cout << -1;
            return 0;
        } else {
            string s1 = "";
            for (int i = s.size() - 1; i >= 0; i--) {
                if (sum % 3 == 0) {
                    s1 = s[i] + s1;
                    continue;
                }
                int x = s[i] - '0';
                if (x % 3 == 2) {
                    sum -= x;
                } else {
                    s1 = s[i] + s1;
                }
            }
            while (s1[0] == '0') {
                s1 = s1.substr(1, s1.size());
            }
            if (s1 == "") s1 = "0";
            cout << s1 << endl;
        }
    } else if (!cnt[2]) {
        if (cnt[1] < 3 && !cnt[0]) {
            cout << -1;
            return 0;
        } else {
            string s1 = "";
            for (int i = s.size() - 1; i >= 0; i--) {
                if (sum % 3 == 0) {
                    s1 = s[i] + s1;
                    continue;
                }
                int x = s[i] - '0';
                if (x % 3 == 1) {
                    sum -= x;
                } else {
                    s1 = s[i] + s1;
                }
            }
            while (s1[0] == '0') {
                s1 = s1.substr(1, s1.size());
            }
            if (s1 == "") s1 = "0";
            cout << s1 << endl;
        }
    } else {
        for (int i = 1; i < s.size(); i++) {
            int x = s[i] - '0';
            if (x % 3 == sum % 3) {
                s.erase(s.begin() + i);
                cout << s;
                return 0;
            }
        }
        if (s[1] != '0') {
            cout << s.substr(1, s.size());
            return 0;
        }
        int del, cnt = 2;
        if (sum % 3 == 1) {
            del = 2;
        } else {
            del = 1;
        }
        int sz = s.size();
        for (int i = sz - 1; i >= 1; i--) {
            int x = s[i] - '0';
            if (x % 3 == del) {
                s.erase(s.begin() + i);
                cnt--;
            }
            if (!cnt) break;
        }
        cout << s;
    }
}