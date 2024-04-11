#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

int n;
string s;

void read() {
    cin >> n;
    cin >> s;
    //cout << n << endl;
}

string get(int l, int r) {
    string ans = "";
    for (int i = l; i <= r; i++) {
        ans += s[i];
    }
    return ans;
}

bool relax(int x) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != 'a' + x) continue;
        if (i > 0) {
            if (s[i - 1] == 'a' + x - 1) {
                string L = get(0, i - 1);
                string R = get(i + 1, s.size() - 1);
                s = L + R;
                return true;
            }
        } 
        if (i < (int)s.size() - 1) {
            if (s[i + 1] == 'a' + x - 1) {
                string L = get(0, i - 1);
                string R = get(i + 1, s.size() - 1);
                s = L + R;
                return true;
            }
        }
    }
    return false;
}

void run() {
    for (int x = 25; x >= 1; x--) {
       // cout << s << endl;
        while (relax(x)) {}
    }
    //cout << s << endl;
}

void write() {
    cout << n - s.size() << endl;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    read();
    run();
    write();
    return 0;
}