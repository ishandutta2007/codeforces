#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, K, N, S;
    cin >> M >> K >> N >> S;

    vi liana(M);
    for (int i = 0; i < M; i++) {
        cin >> liana[i];
        --liana[i];
    }

    const int MAXV = 5e5 + 1;

    vi scheme(S);
    vi need(MAXV);
    for (int i = 0; i < S; i++) {
        cin >> scheme[i];
        need[--scheme[i]]++;
    }

    int use = 0;
    vi have(MAXV);

    for (int i = 0, j = 0; i < M; i++) {
        while (use < S && j < M) {
            use -= min(have[liana[j]], need[liana[j]]);
            have[liana[j]]++;
            use += min(have[liana[j]], need[liana[j]]);
            j++;
        }

        if (use < S && j == M) break;

        int rem_front = i % K;
        int rem_spec = max(0, (j - i) - K);

        if (N * K + rem_front + rem_spec <= M) {
            while (rem_front + N*K <= i) {
                rem_front += K;
            }

            vi print(MAXV);
            vi remove;
            for (int i = 0; i < rem_front; i++)
                remove.push_back(i);
            for (int k = i; k < j; k++) {
                if (print[liana[k]] == need[liana[k]] && rem_spec > 0) {
                    remove.push_back(k);
                    rem_spec--;
                }
                else print[liana[k]]++;
            }

            cout << remove.size() << "\n";
            for (int inx : remove) {
                cout << inx + 1 << " ";
            }
            cout << endl;
            return 0;
        }

        use -= min(have[liana[i]], need[liana[i]]);
        have[liana[i]]--;
        use += min(have[liana[i]], need[liana[i]]);
    }

    cout << -1 << endl;
    return 0;
}