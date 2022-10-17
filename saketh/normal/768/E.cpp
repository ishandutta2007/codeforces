#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

const int MAXV = 60;

unordered_map<int, int> nim[MAXV + 1];

// can forget anything bigger than the pile
int clean(int stones, int state) {
    for (int val = stones + 1; val <= MAXV/2; val++) {
        if ((state >> val) & 1)
            state ^= (1 << val);
    }
    return state;
}

bool see[MAXV + 1][MAXV + 5];

int calc(int stones, int state) {
    state = clean(stones, state);
    if (nim[stones].count(state)) return nim[stones][state];

    for (int i = 0; i < MAXV + 5; i++)
        see[stones][i] = false;

    for (int take = 1; take <= stones; take++) {
        if ((state >> take) & 1) continue;

        int upd = state;
        if (take <= MAXV/2) upd ^= (1 << take);

        int res = calc(stones - take, upd);
        TRACE(cout << "From " << stones << " " << state << " we can go to " << stones - take << " " << upd << " which has res " << res << endl;)
        assert(res >= 0 && res < MAXV + 5);
        see[stones][res] = true;
    }

    int ans = 0;
    while (see[stones][ans]) ans++;

    TRACE(cout << stones << " " << state << " " << ans << endl;)
    return nim[stones][state] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int s;
        cin >> s;
        ans ^= calc(s, 0);
    }

    cout << (ans ? "NO\n" : "YES\n") << endl;
    return 0;
}