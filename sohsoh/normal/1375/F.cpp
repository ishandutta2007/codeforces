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
const ll INF = 1e11;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll C[3], B[3] = {0, 1, 2}, A[3];
bool cmp(ll i, ll j) { return C[i] < C[j]; }

ll U(ll ind, ll d) {
    ind--;
    ll i = 0;
    for (int j = 0; j < 3; j++) if (B[j] == ind) i = j;
    C[ind] += d;
    A[i] += d;
    sort(B, B + 3, cmp);
    sort(A, A + 3);
}

int main() {
    fast_io;
    cin >> C[0] >> C[1] >> C[2];
    A[0] = C[0]; A[1] = C[1]; A[2] = C[2];
    sort(A, A + 3);
    sort(B, B + 3, cmp);

    cout << "First" << endl;
    cout.flush();
    cout << INF << endl;
    cout.flush();
    ll x;
    cin >> x;
    U(x, INF);

    cout << 2 * A[2] - A[1] - A[0] << endl;
    cout.flush();
    cin >> x;
    U(x, 2 * A[2] - A[1] - A[0]);
    cout << A[2] - A[1] << endl;
    cout.flush();
    cin >> x;
    return 0;
}