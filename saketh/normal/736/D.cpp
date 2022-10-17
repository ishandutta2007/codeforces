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

const int MX = 4000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<bitset<MX>> mat(N);

    vector<pair<int, int>> on;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        mat[a-1].set(b-1, true);
        on.emplace_back(a-1, b-1);
    }

    for (int i = 0; i < N; i++)
        mat[i].set(MX/2 + i, true);

    for (int p = 0; p < N; p++) {
        int i = p;
        while (!mat[i][p])
            i++;
        swap(mat[i], mat[p]);

        assert(mat[p][p]);

        for (i = 0; i < N; i++)
            if ((i != p) && mat[i][p])
                mat[i] ^= mat[p];

        assert(mat[p][p]);
    }

    for (int i = 0; i < M; i++) {
        if (mat[on[i].second][on[i].first + MX/2])
            cout << "NO\n";
        else 
            cout << "YES\n";
    }

    return 0;
}