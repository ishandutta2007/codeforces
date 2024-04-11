#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXM = 1e5 + 100;
const int MAXP = 2 * MAXM;
const int MOD = 1e9 + 7;

int N, M;
int a[MAXM];
int b[MAXM];

int way[MAXP];
vector<int> bend[MAXP];
vector<int> bsta[MAXP];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> M;

    vector<int> all;
    all.push_back(0);
    all.push_back(N);

    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
        all.push_back(a[i]);
        all.push_back(b[i]);
    }

    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());

    for (int i = 0; i < M; i++) {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
        b[i] = lower_bound(all.begin(), all.end(), b[i]) - all.begin();

        bsta[a[i]].push_back(i);
        bend[b[i]].push_back(i);
    }

    N = all.size() - 1;

    int cur = 0;
    for (int loc = N; loc >= 0; loc--) {
        if (loc == N) way[loc] = 1;
        else way[loc] = cur;

        for (int i : bend[loc]) {
            cur = (cur + way[loc]) % MOD;
        }

        for (int i : bsta[loc]) {
            cur = (cur - way[b[i]] + MOD) % MOD;
        }
    }

    cout << way[0] << "\n";
}