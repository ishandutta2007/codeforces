#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define gc getchar
#define pc putchar
#define pb push_back
#define X first
#define Y second
#define Mod(x) (((x) % mod + mod) % mod)
#define all(x) x.begin(), x.end()

const int inf = 1e9 + 7;
const double eps = 1e-7;
const double pi = 3.14159265358979323846264338327950288L;

typedef pair <int, int> pii;
typedef long long ll;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}

template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

int k, n, nxt[N], prv[N];
char s[N];
vector <int> vec, rlt;

bool check(int t) {
    return s[t] == '(' && s[nxt[t]] == ')';
}

int main() {
//    freopen("1.in", "r", stdin);
    //freopen("11.out", "w", stdout);
    scanf("%d %d %s", &n, &k, s + 1);
    for (int i = 1; i <= n; i ++) {
        nxt[i] = i + 1;
        prv[i] = i - 1;
        if (check(i)) vec.pb(i);
    }
    for (int i = 0; i < k / 2; i ++) {
        assert(vec.size());
        int c = vec.back();
        vec.pop_back();
        rlt.pb(c), rlt.pb(nxt[c]);
        prv[nxt[nxt[c]]] = prv[c];
        nxt[prv[c]] = nxt[nxt[c]];
        if (check(prv[c])) vec.pb(prv[c]);
    }
    sort(all(rlt));
    for (int i = 0; i < k; i ++) pc(s[rlt[i]]);

    return 0;
}