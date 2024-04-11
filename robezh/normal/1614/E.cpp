#include <bits/stdc++.h>
#include <bits/extc++.h> /** keep-include */
using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
const int mod = (int)1e9 + 1;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
int n;
int off = 0;
Tree<int> tr;

int eval(int x) {
    return x - (int)tr.order_of_key(x) + off;
}

int get_last(int x) {
    int l = -((int)2e5 + 50), r = (int)1e9 + (int)2e5 + 50, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(eval(mid) > x) r = mid;
        else l = mid;
    }
    return l;
}

void add(int x) {
    int a0 = get_last(x - 1);
    int a1 = get_last(x);
    tr.insert(a0);
    tr.insert(a1);
    off += 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int lastans = 0;
    rep(i, 0, n) {
        int T;
        cin >> T;
        add(T);
        int k;
        cin >> k;
        rep(j, 0, k) {
            int x;
            cin >> x;
            x = (x + lastans) % mod;
            lastans = eval(x);
            cout << lastans << '\n';
        }
    }
}