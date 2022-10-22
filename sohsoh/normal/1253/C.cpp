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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], ans[MAXN] = {0}, sum[MAXN] = {0}, n, m;
deque<ll> Q;

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> A[i];
    sort(A, A + n);
    ll s = 0;
    for (int i = 0; i < n; i++) {
        if (Q.size() >= m) {
            s -= Q.front();
            Q.pop_front();
        }

        s += A[i];
        Q.push_back(A[i]);
        sum[i % m] += s;
        ll t_ans = ans[i % m] + sum[i % m];
        cout << t_ans << sep;
        ans[i % m] = t_ans;
    }
    return 0;
}