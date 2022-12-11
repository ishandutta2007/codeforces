#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const int N = 1e6 + 34;

bool u[N];
int k;

int main() {
    //init();
    string s;
    cin >> s;
    int n = s.length();
    sort(s.begin(), s.end());
    int mx = 1, len = 0;
    char ch = s[0];
    char mch;

    s.push_back('!');

    for (int i = 1; i <= n; i++) {
        if (s[i] == ch)
            mx++;
        else {
            if (mx > len) {
                len = mx;
                mch = ch;
            }
            mx = 1;
            ch = s[i];
        }
    }

    int p;
    for (int i = 2; i <= n; i++) {
        p = 2;
        while (i % p) p++;
        if (p * 2 <= n) {
            u[i - 1] = true;
            k++;
        }
    }

    //cerr << s << " " << k << "\n";

    string ss;
    int kk = k;
    for (int i = 0; i < n; i++) {
        if (s[i] != mch) {
            ss.push_back(s[i]);
            continue;
        }
        if (kk) {
            kk--;
        } else {
            ss.push_back(s[i]);
        }
    }

    //cerr << ss << "\n";

    if (k > len)
        cout << "NO\n";
    else {
        cout << "YES\n";
        int c2 = 0;
        for (int i = 0; i < n; i++)
            cout << (u[i] ? mch : ss[c2++]);
    }

    return 0;
}