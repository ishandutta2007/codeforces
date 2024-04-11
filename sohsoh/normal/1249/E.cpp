/*
    Soheil Mohammadkhani
    I will change this text here when i've got "Candidate Master":)
    Editorial Solution :|
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 5e5 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][2] = {0}, n, c, A[MAXN], B[MAXN];

int main() {
    fast_io;
    cin >> n >> c;
    for (int i = 1; i < n; i++) cin >> A[i];
    for (int i = 1; i < n; i++) cin >> B[i];
    dp[0][0] = 0;
    dp[0][1] = c;

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + A[i];
        dp[i][1] = min(dp[i - 1][0] + c, dp[i - 1][1]) + B[i];
    }

    for (int i = 0; i < n; i++) cout << min(dp[i][0], dp[i][1]) << sep;
    cout << endl;
    return 0;
}