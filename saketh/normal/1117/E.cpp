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

    string enc;
    cin >> enc;

    int N = enc.size();

    vector<string> res(3);
    for (int q = 0; q < 3; q++) {
        stringstream ss;
        for (int i = 0; i < N; i++) {
            int tmp = i;
            for (int d = 0; d < q; d++)
                tmp /= 26;
            ss << char('a' + (tmp % 26));
        }
        cout << "? " << ss.str() << endl;
        cin >> res[q];
    }

    vi who(N);
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < 3; q++) {
            int v = res[q][i] - 'a';
            for (int d = 0; d < q; d++)
                v *= 26;
            who[i] += v;
        }
    }

    vector<char> ans(N);
    for (int i = 0; i < N; i++)
        ans[who[i]] = enc[i];

    cout << "! ";
    for (char c : ans)
        cout << c;
    cout << endl;

    return 0;
}