#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

template<typename T> struct BIT{
    int S;
    vector<T> v;

    BIT<T>(int _S){
        S = _S;
        v.resize(S+1);
    }
    
    void update(int i, T k){
        for(i++; i<=S; i+=i&-i)
            v[i] = v[i] + k;
    }

    T read(int i){
        T sum = 0;
        for(i++; i; i-=i&-i)
            sum = sum + v[i];
        return sum;
    }

    T read(int l, int r){
        return read(r) - read(l-1);
    }
};

typedef vector<vector<pair<int, ll>>> tree;

void get_dists(int loc, tree &ch, vll &res) {
    for (auto e : ch[loc]) {
        res[e.first] = res[loc] + e.second;
        get_dists(e.first, ch, res);
    }
}

int inx(vll &coords, ll v) {
    auto it = lower_bound(all(coords), v);
    return it - coords.begin();
}

void solve(int loc, tree &ch, vll &dists, vll &ext, vll &coords, BIT<int> &bit, vi &ans) {
    bit.update(inx(coords, dists[loc] - ext[loc]), 1);
    ans[loc] -= bit.read(0, inx(coords, dists[loc]));

    for (auto e : ch[loc]) {
        solve(e.first, ch, dists, ext, coords, bit, ans);
    }

    ans[loc] += bit.read(0, inx(coords, dists[loc]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vll ext(N);
    for (int i = 0; i < N; i++)
        cin >> ext[i];

    tree ch(N);
    for (int i = 1; i < N; i++) {
        int par, dist;
        cin >> par >> dist;
        ch[par-1].emplace_back(i, dist);
    }

    vll root_dist(N);
    get_dists(0, ch, root_dist);

    vll coord;
    for (int i = 0; i < N; i++) {
        coord.push_back(root_dist[i]);
        coord.push_back(root_dist[i] - ext[i]);
    }

    sort(all(coord));
    coord.erase(unique(all(coord)), coord.end());

    BIT<int> bit(coord.size());

    vi ans(N);
    solve(0, ch, root_dist, ext, coord, bit, ans);

    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}