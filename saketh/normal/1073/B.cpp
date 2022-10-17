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

    vi books(N);
    vi loc(N);
    for (int i = 0; i < N; i++) {
        cin >> books[i];
        books[i]--;
        loc[books[i]] = i;
    }

    int deepest = -1;

    for (int i = 0; i < N; i++) {
        int get;
        cin >> get;
        get--;
        get = loc[get];

        if (get > deepest) {
            cout << get - deepest << " ";
            deepest = get;
        } else cout << 0 << " ";
    }

    cout << endl;
    return 0;
}