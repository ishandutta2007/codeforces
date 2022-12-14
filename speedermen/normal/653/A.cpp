#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    int n, a[12415];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    bool ok = 0;
    FOR(i, 1, n)
        FOR(j, 1, n)
            FOR(k, 1, n)
    if (a[i] == a[j] - 1 && a[j] == a[k] - 1) {
        ok = 1;
    }
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}