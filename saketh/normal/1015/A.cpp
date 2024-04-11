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

    int N, M;
    cin >> N >> M;

    vb hit(M);
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l; j <= r; j++)
            hit[j-1] = true;
    }

    vi ans;
    for (int i = 0; i < M; i++)
        if (!hit[i])
            ans.push_back(i + 1);

    cout << ans.size() << "\n";
    for (int v : ans)
        cout << v << " ";
    cout << endl;

    return 0;
}