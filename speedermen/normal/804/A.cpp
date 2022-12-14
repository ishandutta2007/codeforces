#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
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

int w[N];
long long r;

int g(int v) {
    return v == w[v] ? v : w[v] = g(w[v]);
}

bool unite(int a, int b, int w = 0) {
    a = g(a);
    b = g(b);
    if (a != b) {
        ::w[a] = b;
        r += w;
        return true;
    }
    return false;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    FOR(i, 1, n) w[i] = i;
    int cnt = n;
    FOR(i, 1, n)
        cnt -= unite(i, n + 1 - i);
    FOR(w, 1, n) {
        FOR(i, 1, n) {
            int c = (w + n + 1 - i) % (n + 1);
            if (c != 0) {
                cnt -= unite(i, c, w);
            }
        }
        if (cnt == 1) {
            break;
        }
    }
    cout << r << endl;
    return 0;
}