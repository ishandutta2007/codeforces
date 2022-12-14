#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int a[N], n, k;

long long getmin(int x) {
    long long val = 0;
    FOR(i, 0, n - 1)
        if (a[i] < x)
            val += x - a[i];
    return val;
}

long long getmax(int x) {
    long long val = 0;
    FOR(i, 0, n - 1)
        if (a[i] > x)
            val += a[i] - x;
    return val;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    long long sum = 0;
    FOR(i, 0, n - 1) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    if (sum % n == 0) {
        long long val = 0;
        FOR(i, 0, n - 1)
            val += abs(a[i] - sum / n);
        val /= 2;
        if (val <= k) {
            cout << 0 << endl;
            return 0;
        }
    }
    int lm = a[0], rm = a[n - 1];
    {
        int l = a[0], r = sum / n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (getmin(m) <= k) {
                lm = m;
                l = m + 1;
            } else
                r = m - 1;
        }
    }
    {
        int l = sum / n + 1, r = a[n - 1];
        while (l <= r) {
            int m = (l + r) / 2;
            if (getmax(m) <= k) {
                rm = m;
                r = m - 1;
            } else
                l = m + 1;
        }
    }
    cout << rm - lm << endl;
    return 0;
}