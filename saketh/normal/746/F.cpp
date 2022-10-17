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

typedef set<pair<int, int>> spii;

void rebalance(int W, spii &topW, spii &rest, int &saved) {
    while (topW.size() < W && rest.size() > 0) {
        topW.insert(*rest.rbegin());
        saved += rest.rbegin()->first / 2;
        rest.erase(*rest.rbegin());
    }
    while (rest.size() > 0 && rest.rbegin()->first > topW.begin()->first) {
        auto demote = *topW.begin();
        auto promote = *rest.rbegin();
        topW.erase(demote), rest.insert(demote);
        topW.insert(promote), rest.erase(promote);
        saved -= demote.first/2;
        saved += promote.first/2;
    }
}

void remove(int W, spii &topW, spii &rest, int &saved, pair<int, int> entry) {
    if (topW.count(entry)) {
        topW.erase(entry);
        saved -= entry.first/2;
    } else rest.erase(entry);
    rebalance(W, topW, rest, saved);
}

void offer(int W, spii &topW, spii &rest, int &saved, int val, int inx) {
    rest.insert({ val, inx });
    rebalance(W, topW, rest, saved);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, W, K;
    cin >> N >> W >> K;

    vi pl(N);
    for (int i = 0; i < N; i++)
        cin >> pl[i];

    vi len(N);
    for (int i = 0; i < N; i++)
        cin >> len[i];

    int ans = 0;

    // maintain a set of the top W songs by length
    // saved = how much we save by skipping all of them
    // the proposed extension is always already in the set
    int tail = -1, saved, total, value;
    set<pair<int, int>> topW, rest;

    // iterate over which song to start with, and compute how far we can go
    for (int x = 0; x < N; x++) {
        if (tail < x) {
            saved = 0;
            topW.clear();
            rest.clear();

            offer(W, topW, rest, saved, len[x], x);
            tail = x;
            total = len[x];
            value = pl[x];
        } else {
            remove(W, topW, rest, saved, { len[x-1], x - 1});
            total -= len[x-1];
            value -= pl[x-1];
        }

        while (total - saved <= K && tail < N) {
            ans = max(ans, value);
            tail++;
            if (tail < N) {
                offer(W, topW, rest, saved, len[tail], tail);
                total += len[tail];
                value += pl[tail];
            }
        }
    }

    cout << ans << endl;
    return 0;
}