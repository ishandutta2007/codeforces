#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
#include "cassert"
typedef double ld;
typedef long long ll;
//#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i] - 'a']++;
    }
    char a = '1';
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] == 1) {
            for (int j = 1; j < s.size(); ++j) {
                if (i + 'a' == s[j]) {
                    swap(s[j], s[0]);
                }
            }
            sort(s.begin()+1, s.end());
            cout << s << '\n';
            return;
        } else {
            if (cnt[i] > 1 and a == '1') {
                a = i + 'a';
            }
        }
    }
    string isa, mora;
    for (int i = 0; i < s.size(); ++i) {
        if (a == s[i])
            isa.push_back(s[i]);
        else
            mora.push_back(s[i]);
    }
    isa.pop_back();
    sort(all(mora));
    if (cnt[a-'a'] <= s.size() / 2 + 1) {
        string s2(s.size(), '?');
        s2[0] = s2[1] = a;
        cnt[a-'a'] -= 2;
        for (int i = 3; i < s.size(); i += 2) {
            if (cnt[a-'a']==0)
                break;
            s2[i] = a;
            cnt[a-'a']--;
        }
        int t = 0;
        for (int i = 0; i < s2.size(); ++i) {
            if (s2[i] == '?')
                s2[i] = mora[t++];
        }
        cout << s2 << '\n';
        return;
    }
    if (mora[0] == mora.back()) {
        int t = 0;
        cout << a;
        while (t != mora.size() and mora[t] == mora[0])
            cout << mora[t++];
        cout << isa;
        cout << '\n';
        return;
    }
    cout << a << mora[0] << isa;
    int t = 0;
    //cout << mora;
    while (mora[t] == mora[0])t++;
    //cout << t << endl;
    cout << mora[t];
    for (int i = 1; i < t; ++i) {
        cout << mora[i];
    }
    for (int i = t + 1; i < mora.size(); ++i) {
        cout << mora[i];
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
        solve();
}