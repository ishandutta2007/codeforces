#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    int req;
    cin >> str >> req;

    int cur = str.size();
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?' || str[i] == '*')
            cur -= 2;
    }

    stringstream res;
    for (int i = 0; i < str.size(); ) {
        char nxt = (i + 1) < str.size() ? str[i + 1] : 0;

        if (nxt == '?' || nxt == '*') {
            int add = (nxt == '?') ? 1 : INT_MAX;
            add = max(0, min(add, req - cur));
            for (int j = 0; j < add; j++)
                res << str[i];
            cur += add;
            i += 2;
        } else {
            res << str[i];
            i++;
        }
    }

    if (cur != req)
        cout << "Impossible\n";
    else
        cout << res.str() << "\n";

    return 0;
}