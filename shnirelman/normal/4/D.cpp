#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < m; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int INF = 2e9;

mt19937 rnd(time(0));

struct Envelope {
    int w, h, ind;

    Envelope() {};
};

bool cmp(const Envelope& a, const Envelope& b) {
    if(a.w != b.w)
        return a.w > b.w;
    else
        return a.ind < b.ind;
}

bool is(Envelope out, Envelope in) {
    return out.w > in.w && out.h > in.h;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w, h;
    cin >> n >> w >> h;

    Envelope b;
    b.w = w;
    b.h = h;

    vector<Envelope> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].w >> a[i].h;
        a[i].ind = i;
    }

    sort(a.begin(), a.end(), cmp);

    vector<int> dp(n, 1), p(n, -1);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(is(a[j], a[i]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                p[i] = j;
            }
        }

    int mx = -1;
    for(int i = 0; i < n; i++)
        if(is(a[i], b) && (mx == -1 || dp[mx] < dp[i])) {
            mx = i;
        }

    cout << (mx == -1 ? 0 : dp[mx]) << endl;

    while(mx != -1) {
        cout << a[mx].ind + 1 << ' ';
        mx = p[mx];
    }
}