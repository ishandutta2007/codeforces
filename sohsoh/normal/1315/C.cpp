/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define forr(n)                     for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool used[220];

bool arePermutations(int a[], int b[], int n, int m)
{

    int sum1 = 0, sum2 = 0, mul1 = 1, mul2 = 1;

    // Calculating sum and multiply of first array
    for (int i = 0; i < n; i++) {
        sum1 += a[i];
        mul1 *= a[i];
    }

    // Calculating sum and multiply of second array
    for (int i = 0; i < m; i++) {
        sum2 += b[i];
        mul2 *= b[i];
    }

    // If sum and mul of both arrays are equal,
    // return true, else return false.
    return ((sum1 == sum2) && (mul1 == mul2));
}

void solve() {
    int n;
    cin >> n;
    int* a = new int[2 * n];
    int* perm = new int[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        perm[i] = i + 1;
    }
    for (int i = 0; i < 220; i++) {
        used[i] = 0;
    }
    int* b = new int[n];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        used[k] = true;
        b[i - 1] = k;
        a[2 * i - 2] = k;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (used[j] == false && j > b[i - 1]) {
                a[2 * i - 1] = j;
                used[j] = true;
                break;
            }
        }
    }

    if (*min_element(a, a + 2 * n) == 0 || *max_element(a, a + 2 * n) != 2 * n) {
        cout << -1 << endl;
        return;
    }

    alog(a, 2 * n);
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}