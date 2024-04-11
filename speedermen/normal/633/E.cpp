#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
const int L = 20;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second

int n, k;
int v[N], c[N], st[N];
int mx[L][N], mn[L][N];

int getmx(int l, int r) {
    int d = st[r - l + 1];
    return max(mx[d][l], mx[d][r - (1 << d) + 1]);
}

int getmn(int l, int r) {
    int d = st[r - l + 1];
    return min(mn[d][l], mn[d][r - (1 << d) + 1]);
}

int f(int l, int r) {
    return min(100 * getmx(l, r), getmn(l, r));
}

double solve() {
    long double arr[123] = {};
    long double fact[123] = {};
    fact[0] =1 ;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i -1 ] * i;
    for (int i = 1; i <= n; ++i) {
        arr[i] = 0;
        for (int j = i; j <= n; ++j) {
            arr[i] = max(arr[i], (long double)f(i, j));
        }
    }
    sort(arr + 1, arr + n + 1);
    double ans = 0;
    for (int i = 1; i + k - 1 <= n; ++i) {
        ans += arr[i] * fact[n - i] / fact[k - 1] / fact[(n - i) - (k - 1)];
    }
    ans /= (fact[n] / fact[k] / fact[n - k]);
    return ans;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i) {
        mx[0][i] = v[i];
        mn[0][i] = c[i];
    }
    for (int i = 2; i < N; ++i) st[i] = st[i / 2] + 1;
    for (int l = 1; l < 20; ++l)
        for (int i = 1; i + (1 << l) - 1 <= n; ++i) {
            mx[l][i] = max(mx[l - 1][i], mx[l - 1][i + (1 << (l - 1))]);
            mn[l][i] = min(mn[l - 1][i], mn[l - 1][i + (1 << (l - 1))]);
        }
    vector < int > val;
    for (int L = 1; L <= n; ++L) {
        int l = L, r = n;
        while (l < r - 5) {
            int m = (l + r) / 2;
            if (getmx(L, m) * 100 < getmn(L, m))
                l = m;
            else r = m;
        }
        int cur = 0;
        for (int i = l; i <= r; ++i) {
            cur = max(cur, f(L, i));
        }
        val.push_back(cur);
    }
    sort(val.begin(), val.end());
    long double mul = (long double)1.0 * k / n, ans = 0;
    for (int i = 0; i + k - 1 < val.size(); ++i) {
        ans += mul * val[i];
        mul *= n - k - i;
        mul /= n - 1 - i;
        if (abs(mul) < 1e-30) {
            break;
        }
    }
    cout.precision(10);
    cout << fixed << ans << endl;
    return 0;
}