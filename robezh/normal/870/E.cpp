#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7;

map<int, vector<int> > mp_x, mp_y;

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int f[N], sz[N], e_sz[N];
int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}
void unite(int x, int y) {
    x = find(x), y = find(y);
    e_sz[y]++;
    if(x == y) return ;
    f[x] = y;
    sz[y] += sz[x];
    e_sz[y] += e_sz[x];
}

int n;
int x[N], y[N];
set<int> Sx[N], Sy[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        f[i] = i;
        sz[i] = 1;
        e_sz[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        mp_x[x[i]].push_back(i);
        mp_y[y[i]].push_back(i);
    }
    for(auto p : mp_x) {
        auto &v = p.second;
        sort(v.begin(), v.end(), [](const int i, const int j) {
            return y[i] < y[j];
        });
        for(int i = 1; i < v.size(); i++) unite(v[i], v[i-1]);
    }
    for(auto p : mp_y) {
        auto &v = p.second;
        sort(v.begin(), v.end(), [](const int i, const int j) {
            return x[i] < x[j];
        });
        for(int i = 1; i < v.size(); i++) unite(v[i], v[i-1]);
    }
    for(int i = 0; i < n; i++) {
        Sx[find(i)].insert(x[i]);
        Sy[find(i)].insert(y[i]);
    }
    ll res = 1;
    for(int i = 0; i < n; i++) {
        if(f[i] != i) continue;
        assert(sz[i] <= e_sz[i] + 1);
//        cout << sz[i] << " " << " " << e_sz[i] << endl;
        if(sz[i] == e_sz[i] + 1) res *= fp(2, Sx[i].size() + Sy[i].size()) - 1;
        else res *= fp(2, Sx[i].size() + Sy[i].size());
        res %= mod;
    }
    cout << (res % mod + mod) % mod << endl;


}