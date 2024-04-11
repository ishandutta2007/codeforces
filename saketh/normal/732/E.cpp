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

    int C, S;
    cin >> C >> S;

    vi comp(C), cord(C);
    for (int i = 0; i < C; i++) {
        cin >> comp[i];
        cord[i] = i;
    }
    sort(all(cord), [&](int i, int j) {
        return comp[i] > comp[j];
    });

    vi sock(S), sord(S);
    for (int i = 0; i < S; i++) {
        cin >> sock[i];
        sord[i] = i;
    }
    sort(all(sord), [&](int i, int j) {
        return sock[i] > sock[j];
    });

    vi choice(C, -1);
    vb used(S, false);
    vi adapt(S, 0);

    for (int it = 0; it < 32; it++) {
        int s = 0;
        for (int c = 0; c < C; c++) {
            if (choice[cord[c]] != -1) continue;

            while (s < S && (used[sord[s]] || sock[sord[s]] > comp[cord[c]]))
                s++;
            if (s < S && (sock[sord[s]] == comp[cord[c]])) {
                used[sord[s]] = true;
                choice[cord[c]] = sord[s];
            }
        }

        for (int s = 0; s < S; s++) {
            if (!used[sord[s]]) {
                adapt[sord[s]]++;
                sock[sord[s]] = (sock[sord[s]] + 1) / 2;
            }
        }
    }

    int tc = 0, ta = 0;
    for (int s = 0; s < S; s++) {
        if (used[s]) {
            tc++;
            ta += adapt[s];
        }
    }

    cout << tc << " " << ta << endl;
    for (int s = 0; s < S; s++) {
        if (used[s]) cout << adapt[s] << " ";
        else cout << "0 ";
    }
    cout << endl;

    for (int v : choice)
        cout << v + 1 << " ";
    cout << endl;

    return 0;
}