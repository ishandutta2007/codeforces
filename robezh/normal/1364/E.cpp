#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2049;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int nums[N];

int ask(int x, int y) {
//    return nums[x] | nums[y];
    cout << "? " << x + 1 << " " << y + 1 << '\n';
    fflush(stdout);
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}

int n;
vi idx;
int ans[N];

int get_cur(int cur) {
    int val = (1 << 11) - 1;
    vi is;
    rep(i, 0, n) if(i != cur) is.push_back(i);
    shuffle(all(is), rng);
    for(int i = 0; i < min(15, sz(is)); i++) {
        val &= ask(cur, is[i]);
    }
    return val;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) nums[i] = i;

    shuffle(nums, nums + n, rng);

    idx.resize(n);
    rep(i, 0, n) idx[i] = i;
    shuffle(all(idx), rng);

    int val = get_cur(idx[0]), curi = idx[0];

    for(int i = 1; i < n; i++) {
        int nval = ask(curi, idx[i]);
        if((val | nval) == val) {
            val = get_cur(idx[i]);
//            cout << " to " << val << endl;
            curi = idx[i];
        }
    }
    ans[curi] = val;
    assert(val == 0);
    for(int i = 0; i < n; i++) {
        if(i != curi) ans[i] = ask(curi, i);
    }
    cout << "! ";
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
    fflush(stdout);
//    cout << "! ";
//    for(int i = 0; i < n; i++) cout << nums[i] << " ";
//    cout << '\n';



}