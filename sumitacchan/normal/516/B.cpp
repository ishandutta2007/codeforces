#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;

void imp(){
    Out("Not unique");
    exit(0);
}

signed main(){

    int n, m; cin >> n >> m;
    vector<string> s(n); cin >> s;

    queue<Pii> que;
    int S = 0;
    REP(i, n) REP(j, m) if(s[i][j] == '.'){
        S++;
        int cnt = 0;
        REP(k, 4){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') cnt++;
        }
        if(cnt == 1) que.push(Pii(i, j));
    }

    while(!que.empty()){
        int i = que.front().fi, j = que.front().se;
        que.pop();
        if(s[i][j] != '.') continue;

        int k0 = -1;
        REP(k, 4){
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.'){
                k0 = k;
                break;
            }
        }
        if(k0 == -1) imp();
        int i2 = i + dx[k0], j2 = j + dy[k0];

        if(k0 == 0) s[i][j] = '^', s[i2][j2] = 'v';
        else if(k0 == 1) s[i][j] = '<', s[i2][j2] = '>';
        else if(k0 == 2) s[i][j] = 'v', s[i2][j2] = '^';
        else if(k0 == 3) s[i][j] = '>', s[i2][j2] = '<';
        S -= 2;

        REP(k, 4){
            int i3 = i2 + dx[k], j3 = j2 + dy[k];
            if(i3 >= 0 && i3 < n && j3 >= 0 && j3 < m && s[i3][j3] == '.'){
                int cnt = 0;
                REP(k3, 4){
                    int x = i3 + dx[k3], y = j3 + dy[k3];
                    if(x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') cnt++;
                }
                if(cnt == 1) que.push(Pii(i3, j3));
            }
        }

    }

    if(S != 0) imp();
    else Out(s);

    return 0;
}