#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define x first
#define y second
#define in(n) int (n) = nxt()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef int itn;
typedef pair<int, int> PII;

long long gcd(ll a, ll b) {
    return b > 0 ? gcd(b, a % b) : a;
}
inline int nxt() {
    int a;
    scanf("%d", &a);
    return a;
}

const ll mod = 1000000000 + 7;


int cnt[100000];
int a[100000];
int ans = 0;
int n;
int N;
int ma;

int dfs(int v) {
    int ret = cnt[v];
    if (2 * v + 1 < N) {
        ret = max(ret, dfs(v + v));
        ret = max(ret, dfs(v + v + 1));
    }
    return ret;
}

void upd(int v) {
    cnt[v] = cnt[v >> 1] + a[v];
    if (2 * v + 1 < N) {
        upd(v + v);
        upd(v + v + 1);
    }
}

void solve() {
    int n = nxt();
    long long k = nxt();
    char s[n + 1];
    scanf("%s", s);
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            putchar('1');
        }
        puts("");
        return;
    }

    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    putchar('0');
    for (int i = 1; i < n; ++i) {
        int curlen = i + 1;
        int leab = curlen - pi[i];
        //cout << "L" << leab << endl;
        if (leab * k <= curlen) {
            int cnt = curlen / (leab * k);
            leab *= cnt;
            //cout << cnt << endl;
            if (curlen - leab * k <= leab) {
                putchar('1');
            } else {
                putchar('0');
            }
        } else {
            putchar('0');
        }
    }
    puts("");
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    srand(4524234);

    int t = 1;
    for (int i = 0; i < t; ++i) {
        solve();
    }


#ifdef LOCAL
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}