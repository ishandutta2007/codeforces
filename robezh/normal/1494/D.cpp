#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<int, pii> pe;

const int N = 250005;
int par[N], sal[N], f[N];
int n;
vector<pe> es;

int find(int i) {return f[i] == i ? i : f[i] = find(f[i]);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(par, -1, sizeof(par));
    iota(f, f + N, 0);
    rep(i, 0, n) {
        rep(j, 0, n) {
            int x; cin >> x;
            if(i < j) es.push_back({x, {i, j}});
            else if(i == j) sal[i] = x;
        }
    }
    sort(all(es));
    int r = 0;
    for(int i = 0; i < sz(es); i = r) {
        while(r < sz(es) && es[r].first == es[i].first) r++;
        vector<pii> add;
        rep(j, i, r) {
            int a, b;
            tie(a, b) = es[j].second;
//            cout << a << " " << b << endl;
            a = find(a), b = find(b);
            int &pa = par[a], &pb = par[b];
            int nxt = (pa != -1 ? pa : (pb != -1 ? pb : n++));
            pa = pb = nxt;
//            cout << pa + 1 << " to " << pb + 1 << " to " << nxt + 1 << endl;
            sal[nxt] = es[j].first;
            add.push_back({a, nxt});
            add.push_back({b, nxt});
        }
        for(auto p : add) {
            p.first = find(p.first), p.second = find(p.second);
            if(p.first != p.second) f[p.first] = p.second;
        }
    }
    cout << n << '\n';
    rep(i, 0, n) cout << sal[i] << " ";
    cout << '\n';
    cout << n << "\n";
    rep(i, 0, n - 1) {
        cout << i + 1 << " " << par[i] + 1 << "\n";
    }



}