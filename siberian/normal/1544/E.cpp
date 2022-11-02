#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

vector<int> prefix_function (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

const int A = 26;
string s;

bool isZero() {
    vector<int> cnt(A, 0);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    int good = 0;
    while (good < A && cnt[good] != 1) {
        ++good;
    }
    if (good == A) return false;
    cout << (char)(good + 'a');
    cnt[good]--;
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << (char)(i + 'a');
        }
    }
    cout << '\n';
    return true;
}

bool check(const string& s) {
    if (s.size() <= 2) return true;
    if (s[0] == s[s.size() - 2] && s[1] == s[s.size() - 1]) return false;
    return true;
}

bool checkTwo() {
    vector<int> cnt(A, 0);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    int good = 0;
    while (good < A && cnt[good] == 0) {
        ++good;
    }
    assert(good < A);
    // if (good == A) return false;
    string fans = "";
    fans += good + 'a';
    fans += good + 'a';
    cnt[good] -= 2;
    while (true) {
        bool ok = false;
        for (int i = 0; i < A && !ok; ++i) {
            if (cnt[i] == 0) continue;
            fans += i + 'a';
            if (!check(fans)) {
                fans.pop_back();
            } else {
                ok = true;
                cnt[i]--;
            }
        }
        if (!ok) break;
    }
    // cerr << "fans = " << fans << endl;
    if (fans.size() != s.size()) return false;
    cout << fans << '\n';
    return true; 
}

bool checkFirstSwap() {
    vector<int> cnt(A, 0);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    int start = 0;
    while (start < A && cnt[start] == 0) ++start;
    assert(start < A && cnt[start] >= 2);
    string fans = "";
    fans += start + 'a';
    cnt[start]--;
    
    while (true) {
        bool ok = false;
        for (int i = 0; i < A && !ok; ++i) {
            if (cnt[i] == 0) continue;
            if (fans.size() == 1 && i == start) continue;
            fans += i + 'a';
            if (!check(fans)) {
                fans.pop_back();
            } else {
                ok = true;
                cnt[i]--;
            }
        }
        if (!ok) break;
    }
    if (fans.size() != s.size()) return false;
    // cerr << "s = " << s << endl;
    // cerr << "fans = " << fans << endl;
    // assert(fans.size() == s.size());
    cout << fans;
    cout << '\n';
    return true;
}

void solve() {
    cin >> s;
    sort(all(s));
    if (s[0] == s.back()) {
        cout << s << '\n';
        return;
    }
    if (isZero()) {
        return;
    }
    if (checkTwo()) {
        return;
    }
    if (checkFirstSwap()) {
        return;
    }
    // int ans = s.size();
    // string fans = "";
    // do {
    //     auto p = prefix_function(s);
    //     int have = *max_element(all(p));
    //     if (have < ans) {
    //         ans = have;
    //         fans = s;
    //     }
    //     // chkmin(ans, *max_element(all(p)));
    // } while (next_permutation(all(s)));
    // cout << s << endl;
    // cout << fans << endl;
    // sort(all(s));
    // assert(s[0] == fans[0]);
    // cerr << "puhh" << endl;
    // cout << ans << endl;
    // assert(ans <= 1);
    vector<int> cnt(A, 0);
    for (auto i : s) {
        cnt[i - 'a']++;
    }
    int start = 0;
    while (start < A && cnt[start] == 0) ++start;
    assert(start < A && cnt[start] >= 2);
    string fans = "";
    fans += start + 'a';
    cnt[start]--;
    
    for (int j = start + 1; j < A; ++j) {
        if (cnt[j] == 0) continue;
        while (cnt[j] > 0) {
            fans += j + 'a';
            cnt[j]--;
        } 
        break;
    }

    while (true) {
        bool ok = false;
        for (int i = 0; i < A && !ok; ++i) {
            if (cnt[i] == 0) continue;
            // if (fans.size() == 1 && i == start) continue;
            fans += i + 'a';
            if (!check(fans)) {
                fans.pop_back();
            } else {
                ok = true;
                cnt[i]--;
            }
        }
        if (!ok) break;
    }
    // cerr << "s = " << s << endl;
    // cerr << "fans = " << fans << endl;
    assert(fans.size() == s.size());
    cout << fans;
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
        // cout.flush();
    }    
    return 0;
}