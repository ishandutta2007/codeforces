#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 105;
mt19937 rng(2333);

bool ask(int a, int b) {
    cout << 1 << " " << a << " " << b << '\n';
    fflush(stdout);
    int x; cin >> x;
    return x == 1;
}

int n;

vector<int> quick_sort(vector<int> S) {
    if(sz(S) <= 1) return S;
    shuffle(all(S), rng);
    int p = S.back(); S.pop_back();
    vector<int> L, R;
    for(int x : S) {
        if(ask(p, x)) R.push_back(x);
        else L.push_back(x);
    }
    L = quick_sort(L);
    R = quick_sort(R);
    vi res = L;
    res.push_back(p);
    for(int x : R) res.push_back(x);
    return res;
}

int ask_2(vi &vs, int l, int r, int x) {
    cout << 2 << " " << vs[x] << " " << r - l + 1<< " ";
    rep(i, l, r + 1) cout << vs[i] << " ";
    cout << endl;
    fflush(stdout);
    int res;
    cin >> res;
    return res;

}


bitset<N> res[N];
bitset<N> cur;

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        vi idxs(n, 0);
        iota(all(idxs),0);
        idxs = quick_sort(idxs);
        vector<pii> st;
        cur.reset();
        int l = n - 1;
        int r = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            while(l >= 1 && ask_2(idxs, 0, l - 1, i)) l--;
            if(l == i) {
                rep(j, l, r + 1) cur[idxs[j]] = true;
                rep(j, l, r + 1) res[idxs[j]] = cur;
                l--;
                r = l;
            }
        }

        cout << 3 << '\n';
        rep(i, 0, n) {
            rep(j, 0, n) cout << res[i][j];
            cout << '\n';
        }
        int x;
        cin >> x;
        if(x == -1) break;
        fflush(stdout);
    }

}