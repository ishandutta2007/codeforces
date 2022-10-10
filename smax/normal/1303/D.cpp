#include <bits/stdc++.h>

using namespace std;

#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define f first
#define s second

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << endl;}

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const ll inf = 1e12;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


    ll t; cin >> t;

    while(t--) {
        ll n, m; cin >> n >> m;

        ll arr[m];

        vl v(60);

        ll some = 0;

        f0r(i, m) {
            cin >> arr[i];

            some += arr[i];
            ll whatever = 0;

            while (arr[i] > 1) {
                arr[i] /= 2;
                whatever++;
            }

            v[whatever]++;
        }

        if (some < n) {
            cout << -1 << endl;
            continue;
        }

        ll ret = 0;

        f0r(i, 60) {
            if (i > 0) {
                v[i] += (v[i-1])/2;
            }
            if (n & (1LL << i) ) {
                if (v[i] == 0) {
                    ll variable = 2;
                    ll j = i+1;
                    ret++;
                    while (j < 60 && v[j] == 0) {
                        variable *= 2;
                        ret++;
                        j++;
                    }
                    assert(j != 60);

                    v[i] += v[j] * variable;

                    v[j] = 0;
                }

                v[i]--;

            }
        }

        cout << ret << endl;

    }







}