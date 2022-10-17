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

    int N, M;
    cin >> N >> M;

    N *= 2;
    vi power(N);
    for (int i = 0; i < N; i++) {
        cin >> power[i];
    }

    vb taken(N, false);
    vi force(N, -1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        force[a-1] = b-1;
        force[b-1] = a-1;
    }

    int t;
    cin >> t;

    int theirs = -1;
    for (int _t = 0; _t < N; _t++) {
        if (t == 2) {
            // their turn
            cin >> theirs;
            theirs--;
            taken[theirs] = true;
        } else {
            // our turn

            int choice = -1;
            if (theirs != -1 && force[theirs] != -1 && !taken[force[theirs]]) {
                choice = force[theirs];
            } else {
                for (int i = 0; i < N; i++) {
                    if (taken[i]) continue;
                    if (force[i] != -1) {
                        choice = (power[i] > power[force[i]]) ? i : force[i];
                        break;
                    }
                    if (choice == -1 || power[i] > power[choice])
                        choice = i;
                }
            }

            cout << choice + 1 << endl;
            taken[choice] = true;
        }

        t = 3 - t;
    }

    return 0;
}