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

    string tea = "GB";

    int N, K, A, B;
    cin >> N >> K >> A >> B;

    if (A < B) {
        swap(tea[0], tea[1]);
        swap(A, B);
    }

    int AS = B + 1;
    int worst = (A + AS - 1) / AS;

    if (worst > K) {
        cout << "NO" << endl;
        return 0;
    }

    vi aput(AS);
    for (int i = 0; i < A; i++)
        aput[i % AS]++;

    for (int i = 0; i < AS; i++) {
        if (i) cout << tea[1];
        for (int j = 0; j < aput[i]; j++)
            cout << tea[0];
    }
    cout << endl;

    return 0;
}