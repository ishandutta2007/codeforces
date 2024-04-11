#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;
const int MAXD = 300;

vector<int> divisors(int V) {
    vector<int> res;
    for (ll d = 1; d * d <= V; d++) {
        if (V % d) continue;
        res.push_back(d);
        if (d * d != V) res.push_back(V / d);
    }
    return res;
}

int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a%b);
}

int N;
int arr[MAXN * 2];
int cnt[MAXN];

vector<int> lens[MAXD];
int big[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i+N] = arr[i];
    }

    vector<int> divs = divisors(N);
    sort(divs.begin(), divs.end());

    for (int len = 1; len < N; len++) {
        int g = gcd(N, len);
        int i = lower_bound(divs.begin(), divs.end(), g) - divs.begin();
        lens[i].push_back(len);
    }

    ll ans = 0;

    for (int idx = 0; idx < divs.size(); idx++) {
        int d = divs[idx];
        memset(big, 0, sizeof(big));

        int r = 0;
        for (int j = 0; j < N; j++) {
            big[r] = max(big[r], arr[j]);
            r++;
            if(r == d) r = 0;
        }

        int streak = 0;
        for (int i = 2 * N - 1; i >= 0; i--) {
            if (arr[i] == big[i % d]) {
                streak++;
                if (i < N)
                cnt[min(N, streak)]++;
            } else streak = 0;
        }

        for (int siz = MAXN - 1; siz > 0; siz--) {
            while(lens[idx].size() > 0 && lens[idx].back() > siz) lens[idx].pop_back();
            ans += lens[idx].size() * 1ll * cnt[siz];
            cnt[siz] = 0;
        }
    }

    cout << ans << "\n";
}