#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <map>
#include <set>
#include <deque>
#include <iomanip>
#include <bitset>
#include <random>

#define int long long
// #define int short
#define str string
#define pb push_back
#define pii pair<int, int>
using namespace std;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q;
    while (q--) {
        str s, t;
        cin >> s >> t;
        vector<int> uk(s.size());
        vector<vector<int>> heh(26, uk);
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            char p = s[i];
            int l = last[p - 'a'];
            for (int j = l + 1; j <= i; j++) {
                heh[p - 'a'][j] = i;
            }
            last[p - 'a'] = i;
        }
        for (int y = 0; y < 26; y++) {
            for (int p = last[y] + 1; p < s.size(); p++) {
                heh[y][p] = -1;
            }
        }
        int ans = 0;
        int tuk = 0;
        while (tuk < t.size() && ans <= t.size() + 10) {
            int now = -1;
            while (now < s.size() - 1 && tuk < t.size()) {
                now = heh[t[tuk] - 'a'][now+1];
                if (now == -1) {
                    break;
                }
                tuk++;
            }
            ans++;
        }
        if (ans > t.size()) {
            cout << "-1";
        } else {
            cout << ans;
        }
        cout << '\n';
    }
}