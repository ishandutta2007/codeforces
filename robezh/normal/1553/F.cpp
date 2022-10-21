#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int B = 501, N = (int)3e5 + 5;

int n;
ll psum[N], pcnt[N];
int a[N];
ll res[N];
vi xs;

void build(int x) {
    memset(psum, 0, sizeof(psum));
    memset(pcnt, 0, sizeof(pcnt));
    rep(i, 0, x + 1) {
        psum[a[i]] = a[i];
        pcnt[a[i]] = 1;
    }
    rep(i, 1, N) psum[i] += psum[i - 1], pcnt[i] += pcnt[i - 1];
    xs.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        if(i) res[i] = res[i - 1];
        ll add = 0;
        int v = a[i];
        for (int i = 1, j = 0; i <= v; i = j + 1)  {
            j = v / (v / i);
//            cout << i << " " << j << " " << n / i << endl;
            add -= (psum[j] - psum[i - 1])*(v/i);
        }
        add += pcnt[v] * v;
        add += psum[v];
//        cout << "low add: " << add << endl;

        ll add2 = 0;
        for(int j = v; j < N; j += v) {
            int r = min(j + v - 1, N - 1), l = j;
            add2 += (psum[r] - psum[l - 1]) - (pcnt[r] - pcnt[l - 1]) * j;
        }
        add2  += (pcnt[N - 1] - pcnt[v]) * v;
        for(int o : xs) {
            res[i] += o % v + v % o;
        }

//        cout << "high add: " << add2 << endl;
        res[i] += add + add2;
        xs.push_back(v);
        if((i + 1) % B == 0) {
            build(i);
        }
    }
    rep(i, 0, n) cout << res[i] << " ";
    cout << '\n';
}