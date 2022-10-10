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

#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}

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

    ll n, need;

    cin >> n >> need;

    vl arr(n);

    ll t = 0;

    f0r(i, n) {
        cin >> arr[i];
        t += arr[i];
    }

    ll pref[n + 1];

    if (t < need) {
        cout << -1 << endl;
        return 0;
    }

    sort(arr.begin(), arr.end());

    pref[0] = 0;

    for (int i = 1; i <= n; i++) {
        pref[i] = arr[n - i] + pref[i - 1];
    }

    //ao(pref, n + 1);

    t = 0;

    int l = 1, r = n + 1;
    while (l < r) {
        int m = (l + r) / 2;

        ll s = pref[m];

        ll pen = 1;
        ll cnt = 0;
        ll i = m-1;

        for (int j = n - i - 2; j >= 0; j--) {
            s += max(0LL, arr[j] - pen);
            cnt += 1;
            if (cnt == (i + 1)) {
                pen += 1;
                cnt = 0;
            }
        }


        if (s < need) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    cout << l << endl;




}