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

    vi who(N), bid(N);
    vi last(N, -1);
    vi order;
    vvi amts(N);

    for (int i = 0; i < N; i++) {
        cin >> who[i] >> bid[i];
        who[i]--;
        if (last[who[i]] == -1)
            order.push_back(who[i]);
        last[who[i]] = i;
        amts[who[i]].push_back(bid[i]);
    }

    sort(all(order), [&](int i, int j) {
        return last[i] > last[j];
    });

    for (int i = 0; i < N; i++)
        sort(all(amts[i]));

    vb elim(N);

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int S;
        cin >> S;
        vi rem(S);
        for (int i = 0; i < S; i++) {
            cin >> rem[i];
            elim[--rem[i]] = true;
        }

        int win = 0;
        while (win < order.size() && elim[order[win]])
            win++;

        if (win == order.size()) {
            cout << "0 0\n";
        } else {
            int snd = win + 1;
            while (snd < order.size() && elim[order[snd]])
                snd++;

            int beat = snd < order.size() ? amts[order[snd]].back() : 0;
            auto it = upper_bound(all(amts[order[win]]), beat);

            cout << order[win] + 1 << " " << *it << "\n";
        }

        for (int v : rem)
            elim[v] = false;
    }

    return 0;
}