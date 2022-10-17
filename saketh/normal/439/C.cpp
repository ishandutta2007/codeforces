#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 500;

int N, K, P, V;
vector<int> even, odd;

void fail() {
    cout << "NO\n";
    exit(0);
}

vector<int> groups[MAXN];

void put(int i, vector<int> &src) {
    groups[i].push_back(src.back());
    src.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> K >> P;

    for (int i = 0; i < N; i++) {
        cin >> V;
        if (V&1) odd.push_back(V);
        else even.push_back(V);
    }

    int EVEN = P;
    int ODD = K - P;

    if (odd.size() < ODD) fail();

    int FO = odd.size() - ODD;
    if (FO % 2 == 1) fail();

    if (even.size() + (FO / 2) < EVEN) fail();

    cout << "YES\n";

    for (int i = 0; i < K; i++) {
        if (i < ODD) {
            put(i, odd);
        } else {
            if (even.size()) {
                put(i, even);
            } else {
                put(i, odd);
                put(i, odd);
            }
        }
    }

    while (even.size()) put(0, even);
    while (odd.size()) put(0, odd);

    for (int i = 0; i < K; i++) {
        cout << groups[i].size() << " ";
        for (int v : groups[i]) cout << v << " ";
        cout << "\n";
    }
}