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

int get(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int res;
    cin >> res;
    return res;
}

/*int a = 712309832, b = 24442342;
int get(int c, int d) {
    int ac = a ^ c, bd = b ^ d;
    return (ac == bd) ? 0 : (ac > bd) ? 1 : -1;
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A = 0, B = 0;
    bool abig = get(0, 0) >= 0;

    for (int i = 29; i >= 0; i--) {
        int r10 = get(A + (1 << i), B);
        int r01 = get(A, B + (1 << i));

        if (r10 != r01) {
            if (r01 == 1) {
                A += 1 << i;
                B += 1 << i;
            }
        } else {
            if (abig) {
                A += 1 << i;
                abig = r10 >= 0;
            }
            else {
                B += 1 << i;
                abig = r01 >= 0;
            }
        }
    }

    cout << "! " << A << " " << B << endl;

    return 0;
}