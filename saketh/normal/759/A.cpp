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

int solvePerm(vi &p) {
    vvi families;
    vb seen(p.size());

    for (int i = 0; i < p.size(); i++) {
        if (seen[i]) continue;

        vi fam;
        for (int loc = i; !seen[loc]; loc = p[loc]) {
            fam.push_back(loc);
            seen[loc] = true;
        }

        families.push_back(fam);
    }

    int F = families.size();
    if (F == 1) return 0;

    /*for (int i = 0; i < F; i++) {
        int n = (i + 1) % F;
        p[families[i].back()] = families[n].front();
    }*/

    return families.size();
}

int solveFlip(vi &b) {
    int sum = 0;
    for (int v : b)
        sum += v;

    if (sum&1) return 0;

    b[0] = !b[0];
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi p(N), b(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int ans = solvePerm(p) + solveFlip(b);
    cout << ans << "\n";
    /*for (int v : p)
        cout << v + 1 << " ";
    cout << "\n";
    for (int v : b)
        cout << v << " ";
    cout << endl;*/

    return 0;
}