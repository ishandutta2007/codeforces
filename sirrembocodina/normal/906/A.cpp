#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int cnt = 0, ans = 0;
    vector<bool> was(26, false);
    forn (i, n) {
        string s;
        cin >> s;
        if (s[0] == '?') {
            cin >> s;
            if (cnt == 25 && i != n - 1) {
                ++ans;
            }
            cnt += !was[s[0] - 'a'];
            was[s[0] - 'a'] = true;
        } else if (s[0] == '!') {
            if (cnt == 25) {
                ++ans;
            }
            cin >> s;
            forn (i, 26) {
                bool t = false;
                forn (j, s.size()) {
                    if (s[j] == 'a' + i) {
                        t = true;
                    }
                }
                if (!t) {
                    cnt += !was[i];
                    was[i] = true;
                }
            }
        } else {
            cin >> s;
            forn (i, s.size()) {
                cnt += !was[s[i] - 'a'];
                was[s[i] - 'a'] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}