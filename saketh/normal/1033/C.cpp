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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi perm(N);
    vi loc(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> perm[i];
        loc[perm[i]] = i;
    }

    vb win(N, false);
    for (int num = N; num >= 1; num--) {
        bool res = false;
        for (int succ = loc[num] - num; succ >= 0; succ -= num) {
            res |= (perm[succ] > num) && (!win[succ]);
        }
        for (int succ = loc[num] + num; succ < N; succ += num) {
            res |= (perm[succ] > num) && (!win[succ]);
        }
        win[loc[num]] = res;
    }

    for (bool b : win)
        cout << (b ? 'A' : 'B');
    cout << endl;
    return 0;
}