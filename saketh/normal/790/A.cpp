#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

string make(int val) {
    if (val < 26) {
        string res = "A";
        res[0] += val;
        return res;
    }

    string res = "Aa";
    res[1] += val - 26;
    return res;
}

int find_missing(vi &res, int i, int j, int K) {
    vb found(K);
    for (int a = i; a <= j; a++)
        found[res[a]] = true;
    for (int i = 0; i < K; i++)
        if (!found[i]) return i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    int G = N - K + 1;

    vector<bool> distinct(G);

    for (int i = 0; i < G; i++) {
        string inp;
        cin >> inp;
        distinct[i] = (inp == "YES");
    }

    // find the first "YES"
    int f = 0;
    while (f < G && !distinct[f]) f++;

    vector<int> res(N, 0);

    // from the "YES", put distinct values
    if (f < G) {
        for (int i = f + 1; i < f + K; i++)
            res[i] = i - f;
        for (int i = f + K; i < N; i++) {
            if (distinct[i - K + 1]) {
                // find what to restore
                res[i] = find_missing(res, i - K + 1, i - 1, K);
            } else {
                // put whatever is at the beginning
                res[i] = res[i - K + 1];
            }
        }
    }

    for (int r : res)
        cout << make(r) << " ";
    cout << endl;

    return 0;
}