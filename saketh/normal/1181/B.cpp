#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

string build(string str, int left, int LEN) {
    string a = str.substr(0, left), b = str.substr(left);
    reverse(all(a));
    reverse(all(b));

    vector<int> digs;
    for (int i = 0, c = 0; i <= LEN; i++) {
        int s = c
              + (i < sz(a) ? (a[i] - '0') : 0)
              + (i < sz(b) ? (b[i] - '0') : 0);
        digs.push_back(s % 10);
        c = s / 10;
    }

    reverse(all(digs));
    stringstream ss;
    for (int d : digs) ss << d;
    return ss.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string str;
    cin >> N >> str;

    vector<int> split;
    for (int fr = 1; fr < sz(str); fr++) {
        if (str[fr] != '0')
            split.push_back(fr);
    }

    int c1 = lower_bound(all(split), sz(str)/2) - split.begin();

    vector<string> cand;
    for (int inx = c1 - 1; inx <= c1 + 1; inx++) {
        if (0 <= inx && inx < sz(split)) {
            cand.push_back(build(str, split[inx], sz(str) + 1));
        }
    }

    string ans = *min_element(all(cand));
    reverse(all(ans));
    while(ans.back() == '0') ans.pop_back();
    reverse(all(ans));

    cout << ans << endl;

    return 0;
}