#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int n,m;
vector<vi> horiz, vert;

bool inbounds(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int get_len(int fx, int fy, int tx, int ty) {
    if (fx != tx) {
        return vert[min(fx,tx)][fy];
    }

    return horiz[fx][min(fy,ty)];
}

int dist[21][21];
int nd[21][21];
int tmp[510][510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int k;
    cin >> n >> m >> k;

    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << " ";
            }
            cout << '\n';
        }
        return 0;
    }

    k /= 2;

    int orig_k = k;
    k = (k+1)/2;

    horiz = vector<vi>(n, vi(m-1));
    vert = vector<vi>(n-1, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            cin >> horiz[i][j];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vert[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            memset(dist,0x3f, sizeof(dist));
            memset(nd,0x3f, sizeof(dist));
            nd[10][10] = 0;

            tmp[i][j] = 1000000000;

            for (int it = 0; it < k; it++) {
                for (int x = 10-it; x <= 10+it; x++) {
                    int used = abs(10-x);
                    for (int y = 10-(it-used); y <= 10+(it-used); y++) if (inbounds(i+x-10, j+y-10)) {
                        dist[x][y] = nd[x][y];
                        nd[x][y] = 1000000000;
                    }
                }

                for (int x = 10-it; x <= 10+it; x++) {
                    int used = abs(10-x);
                    for (int y = 10-(it-used); y <= 10+(it-used); y+=2) if (inbounds(i+x-10, j+y-10)) {
                        // dbg(it,x,y);
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (inbounds(i+nx-10, j+ny-10)) {
                                nd[nx][ny] = min(nd[nx][ny], dist[x][y] + get_len(i+x-10, j+y-10, i+nx-10, j+ny-10));
                                
                                if (it == k-1) tmp[i][j] = min(tmp[i][j], nd[nx][ny]);
                            }
                        }
                    }
                }
            }

            // cout << tmp[i][j] << ' ';
        }
        // cout << '\n';
    }

    k = orig_k - k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            memset(dist,0x3f, sizeof(dist));
            memset(nd,0x3f, sizeof(dist));
            nd[10][10] = 0;

            int ans = 1000000000;

            for (int it = 0; it < k; it++) {
                for (int x = 10-it; x <= 10+it; x++) {
                    int used = abs(10-x);
                    for (int y = 10-(it-used); y <= 10+(it-used); y++) if (inbounds(i+x-10, j+y-10)) {
                        dist[x][y] = nd[x][y];
                        nd[x][y] = 1000000000;
                    }
                }

                for (int x = 10-it; x <= 10+it; x++) {
                    int used = abs(10-x);
                    for (int y = 10-(it-used); y <= 10+(it-used); y+=2) if (inbounds(i+x-10, j+y-10)) {
                        // dbg(it,x,y);
                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (inbounds(i+nx-10, j+ny-10)) {
                                nd[nx][ny] = min(nd[nx][ny], dist[x][y] + get_len(i+x-10, j+y-10, i+nx-10, j+ny-10));
                                
                                dbg(nx,ny,nd[nx][ny]);
                                if (it == k-1) ans = min(ans, nd[nx][ny] + tmp[i+nx-10][j+ny-10]);
                            }
                        }
                    }
                }
            }

            if (k == 0) ans = tmp[i][j];
            cout << ans*2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}