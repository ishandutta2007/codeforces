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

const int N = 1000 * 1000 + 560;
vector<int> g[N];
int n, m;
vector<int> colors[N];

void gen() {
    n = 50000;
    m = 100000;
    forn (i, m) {
        int a = ((rand() << 15) ^ rand()) % n;
        int b = ((rand() << 15) ^ rand()) % n;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, n) 
        forn (j, 16)
            colors[i].pb(rand() + 1);   
}

bool read() {
    //gen();
   // return true;
    cin >> n >> m;
    forn (i, m) {
        int a, b;      
        scanf("%d%d", &a, &b);
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    forn (i, n) {
        int k;
        cin >> k;
        colors[i].resize(k);
        forn (j, k)
            scanf("%d", &colors[i][j]);
    }
    return true;
}

int c[N];
int team[N];

vector<int> ver[N];
      
inline int calcbal(int v) {
    int bal = 0;
    for (int i : ver[v]) {
        for (int to : g[i])
            if (c[to] != c[i]) {
                bal += (team[c[to]] == team[c[i]] ? 1 : -1);
            }
    }
    return bal;    
}

int bal[N];

inline void switchteam(int v, set<pt> &s) {
    for (int i : ver[v]) {
        for (int to : g[i])
            if (c[to] != c[i]) {
                s.erase(mp(bal[c[to]], c[to]));
                bal[c[to]] -= (team[c[i]] == team[c[to]] ? 2 : -2);
                if (bal[c[to]] > 0)
                    s.insert(mp(bal[c[to]], c[to]));
            }
    }    
    team[v] ^= 1;
    bal[v] = -bal[v];
}

void solve() {
    
    int k = 0;
    forn (i, n)
        forn (j, sz(colors[i]))
            k = max(k, colors[i][j]);

    while(true) {
        forn (i, N)
            ver[i].clear();
        forn (i, n) {
            c[i] = colors[i][rand() % sz(colors[i])];
            ver[c[i]].pb(i);
            team[c[i]] = 0;
        }
        
        set<pt> s;
        forn (i, N) {
            bal[i] = calcbal(i);
            if (bal[i] > 0)
                s.insert(mp(bal[i], i));
        }

        int sum = 0;

                while(!s.empty()) {
            int v = s.rbegin()->sc;
            s.erase(*s.rbegin());                        
            switchteam(v, s);
        }     

        int cnt = 0;
        forn (i, n) {
            for (int to : g[i])
                if (c[i] != c[to] && team[c[i]] != team[c[to]])
                    cnt++;
        }
        cnt /= 2;
        //cerr << cnt << endl;
        if (cnt * 2 >= m) {
            forn (i, n)
                printf("%d ", c[i]);
            puts("");
            for (int i = 1; i <= k; ++i)
                printf("%d ", team[i] + 1);
            puts("");
            return;
        }
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