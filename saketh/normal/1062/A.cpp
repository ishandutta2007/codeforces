#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    vals.insert(vals.begin(), 0);
    vals.push_back(1001);
    N += 2;

    int ans = 0;
    for (int i = 0; i < N; ) {
        int j = i;
        while ((j+1 < N) && (vals[j]+1 == vals[j+1]))
            j++;
        ans = max(ans, j - i - 1);
        i = j + 1;
    }

    cout << ans << endl;
    return 0;
}