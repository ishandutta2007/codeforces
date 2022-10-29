#include<bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

int n;
const int N = 200 * 1000 + 5;
int c[N];
vector<int> g[N];

bool read() {
    cin >> n;
    forn (i, n) {
        cin >> c[i];
        if (c[i] == 1)
            c[i] = 0;
        else
            c[i] = 1;
    }
    forn (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    return true;
}

int sum[N];

int calc(int v, int p = -1) {
    sum[v] = c[v];
    for (int to : g[v])
        if (to != p)
            sum[v] += calc(to, v);
    return sum[v];
}
 
int cnt;

void change(int v) {
    sum[v] += 1 - 2 * c[v];
    cnt -= c[v];
    c[v] ^= 1;
    cnt += c[v];
}

void dfs(int v, int p = -1) {
    printf("%d ", v + 1);
    forn (it, 2) {
        for (int to : g[v]) {
            if (to == p)
                continue;
            if (sum[to] == 1) {
                if (c[to] == 1) {
                    printf("%d ", to + 1);
                    sum[v] -= sum[to];
                    change(to);
                    if (cnt == 0)
                       exit(0);
                    sum[v] += sum[to];
                    change(v);
                    printf("%d ", v + 1);
                }
            }
            if (sum[to] > 0) {   
                sum[v] -= sum[to];
                change(to);
                dfs(to, v);
                if (cnt == 0)
                    exit(0);
                printf("%d ", v + 1);
                change(v);
                sum[v] += sum[to];
                if (cnt == 0)
                    exit(0);
            }
        }
    }
}


void solve() {
    calc(0);
    cnt = sum[0];
    dfs(0);
    if (cnt == 1) {
        assert(c[0] == 1);
        cout << g[0][0] + 1 << ' ' << 1 << ' ' << g[0][0] + 1 << endl;
        return;
    }
}

int main() {
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
    
    read();
	solve();     
    

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}