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
    cin >> str;

    int N = str.size();

    set<char> non_center;
    for (int i = 0; i < N - i - 1; i++) {
        non_center.insert(str[i]);
    }

    if (non_center.size() <= 1) {
        cout << "Impossible\n";
        return 0;
    }
    // At least two distinct characters appear in the left half.
    // That means we can always do this with <= 2 cuts.

    for (int cut = 1; cut < N; cut++) {
        stringstream ss;
        ss << str.substr(cut);
        ss << str.substr(0, cut);
        string cand = ss.str();

        if (cand == str) continue;
        bool palin = true;
        for (int i = 0; i < N - i - 1; i++) {
            if (cand[i] != cand[N - i - 1])
                palin = false;
        }
        if (palin) {
            cout << 1 << endl;
            return 0;
        }
    }

    cout << 2 << endl;
    return 0;
}