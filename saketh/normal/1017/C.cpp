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

    int bbs = 1, ans = N + 1;
    for (int bs = 2; bs <= N; bs++) {
        int res = bs + ((N + bs - 1) / bs);
        //cout << bs << " gives " << res << endl;
        if (res < ans) {
            bbs = bs;
            ans = res;
        }
    }

    vi res(N);
    for (int i = 0; i < N; i++) {
        res[i] = i;
    }

    for (int i = 0; i < N; i += bbs) {
        vi::iterator end;
        if (i + bbs <= N)
            end = res.begin() + i + bbs;
        else
            end = res.end();
        reverse(res.begin() + i, end);
    }

    for (int v : res) cout << v + 1 << " ";
    cout << endl;

    return 0;
}