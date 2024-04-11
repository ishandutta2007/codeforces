/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, P[MAXN], Q[MAXN], A[MAXN];
vector<pll> ans;

ll do_job() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= A[i]; j++) {
            if (A[j] <= i) {
                swap(P[i], P[j]);
                ans.push_back({i + 1, j + 1});
                swap(A[i], A[j]);
                return 0;
            }
        }
    }
}

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> Q[i];
    ll t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (P[i] == Q[j]) {
                A[i] = j;
                t += abs(i - j);
            }
        }
    }

    cout << t / 2 << endl;

    while (true) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (P[i] != Q[i]) {
                ok = false;
                break;
            }
        }

        if (ok) break;
        do_job();
    }
    cout << ans.size() << endl;
    for (pll e : ans) {
        cout << e.X << sep << e.Y << endl;
    }
    return 0;
}