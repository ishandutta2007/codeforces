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

const int N = 100000;

struct edge {
    int to, cost, cap, flow, back;
};

vector<edge> g[N];

void addedge(int a, int b, int cost, int cap) {
    edge e1 = {b, cost, cap, 0, sz(g[b])};
    edge e2 = {a, -cost, 0, 0, sz(g[a])};
    g[a].pb(e1);
    g[b].pb(e2);        
}

int n;
string a;
int m;
string b[200];
int c[200];
int x;

bool read() {
    cin >> n;
    cin >> a;
    cin >> m;
    forn (i, m) {
        cin >> b[i] >> c[i];            
    }
    cin >> x;
    return true;
}

int d[N];
bool inq[N];

pt p[N];
int cost = 0;

bool enlarge(int s, int t) {
    queue<int> q;
    q.push(s);              
    forn (i, N)
        d[i] = 2 * INF;
    d[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        inq[v] = false;
        q.pop();
        forn (i, sz(g[v])) {
            edge e = g[v][i];
            int to = e.to;
            if (e.cap == e.flow) 
                continue;
            if (d[to] > d[v] + e.cost) {
                d[to] = d[v] + e.cost;
                p[to] = mp(v, i);
                if (!inq[to]) {
                    inq[to] = true;
                    q.push(to);
                }
            }
        }
    }
    if (d[t] == 0)
        return false;
    cost += d[t];
    while(t != s) {
        int v = p[t].x;
        int i = p[t].y;
        g[v][i].flow++;
        g[g[v][i].to][g[v][i].back].flow--;
        t = v;
    }
    return true;
}

const int M = 1e5;
       
void solve() {
    int t = n;
    int s = t + 1;
    forn (i, n)
        addedge(i, i + 1, M, x);
    forn (i, n) {
        forn (j, m) {
            int cnt = 0;
            forn (k, sz(b[j]))
                if (i + k < n)
                    cnt += a[i + k] == b[j][k];
            if (cnt == sz(b[j])) {
                addedge(i, i + sz(b[j]), sz(b[j]) * M - c[j], 1);        
            }
        }
    }
    addedge(s, 0, 0, x);
    forn (i, x) {
        assert(enlarge(s, t));
    }
    cout << n * M * x - cost << endl;
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