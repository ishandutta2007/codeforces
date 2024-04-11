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

    vector<pair<int, int>> stud;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int v;
            cin >> v;
            sum += v;
        }
        stud.emplace_back(-sum, i);
    }

    sort(all(stud));

    for (int i = 0; i < N; i++) {
        if (stud[i].second == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}