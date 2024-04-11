#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sum = 0;
    string s;
    cin >> s;
    long long i = 0;
    while (i < s.size()) {
        long long x = s[i] - '0';
        long long now = 0;
        long long cnt = -1000;
        if (x >= 0 && x < 10) {
            while (i < s.size() && (x >= 0 && x < 10)) {
                cnt++;
                now = now * 10 + x;
                i++;
                if (i < s.size() && s[i] == '.') {
                    cnt = 0;
                    i++;
                }
                if (i < s.size()) x = s[i] - '0';
            }
        }
        if (cnt != 2) {
            now *= 100;
        }
        if (now != 0) {
            sum += now;
        }
        i++;
    }
    //cout << sum << endl;
    string s1 = "";
    if (sum % 100 != 0) {
        s1 = (char) ((sum % 10) + '0') + s1;
        sum /= 10;
        s1 = (char) ((sum % 10) + '0') + s1;
        sum /= 10;
        s1 = '.' + s1;
    } else {
        sum /= 100;
    }
    if (sum == 0) {
        s1 = '0' + s1;
    }
    long long cnt = 0;
    while (sum != 0) {
        if (cnt == 3) {
            s1 = '.' + s1;
            cnt = 0;
        }
        s1 = (char) ((sum % 10) + '0') + s1;
        sum /= 10;
        cnt++;
    }
    cout << s1 << endl;
}