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
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    const int MAXV = 1e6 + 1;

    int N;
    cin >> N;

    vi vals(N);
    vi ct(MAXV);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        ct[vals[i]]++;
        sum += vals[i];
    }

    vi res;
    for (int i = 0; i < N; i++) {
        ll rest = sum - vals[i];
        if (rest % 2 == 0 && rest / 2 < MAXV && ct[rest / 2] - (vals[i] == rest / 2) > 0)
            res.push_back(i);
    }

    cout << res.size() << "\n";
    for (int v : res)
        cout << v + 1 << " ";
    cout << endl;

    return 0;
}