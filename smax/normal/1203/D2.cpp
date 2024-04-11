#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<char, unordered_set<int, custom_hash>, custom_hash> last;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    int ptr = t.length() - 1;
    for (int i=s.length()-1; i>=0; i--)
        if (s[i] == t[ptr]) {
            last[s[i]].insert(i);
            ptr--;
        }

    int i = 0, tPtr1 = 0, tPtr2 = 0, ret = 0;
    for (int j=0; j<s.length(); j++) {
        if (tPtr2 < t.length() && t[tPtr2] == s[j] && last[s[j]].count(j))
            tPtr2++;
        while (i < s.length() && tPtr1 < tPtr2) {
            if (s[i] == t[tPtr1])
                tPtr1++;
            i++;
        }
        ret = max(ret, j - i + 1);
    }

    cout << ret << "\n";

    return 0;
}