#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
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

    vector<pair<int, int>> vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i].first;
        vals[i].second = i + 1;
    }

    sort(all(vals));

    for (int i = 0; i < N / 2; i++) {
        cout << vals[i].second << " " << vals[N - 1 - i].second << "\n";
    }

    return 0;
}