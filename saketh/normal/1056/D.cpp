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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi tree(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        tree[p-1].push_back(i);
    }

    vi siz(N);
    for (int i = N - 1; i >= 0; i--) {
        if (tree[i].size() == 0)
            siz[i] = 1;
        else for (int ch : tree[i])
            siz[i] += siz[ch];
    }

    sort(all(siz));
    for (int v : siz)
        cout << v << " ";
    cout << endl;

    return 0;
}