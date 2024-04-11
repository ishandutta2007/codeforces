#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

const int MAXN = 2e5 + 10;
int p[MAXN], pos[MAXN], bit[MAXN];

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

struct BIT {
    ll B[MAXN];
    void upd(int p, ll v) {
        for(; p < MAXN; p += (p & -p))
            B[p] += v;
    }

    ll sum(int p) {
        ll res = 0;
        for(; p; p -= (p & -p))
            res += B[p];
        return res;
    }
};

BIT inv, oth;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    Tree<int> posits;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int po = pos[i];
        ans += i - 1 - inv.sum(po);
        inv.upd(po, 1);
        oth.upd(po, po);
        posits.insert(po);
        int m = *posits.find_by_order(i / 2);
        ll bel = i/2;
        ll tot = 0;
        tot += (bel * m - oth.sum(m - 1) - bel*(bel + 1)/2);
        ll abv = i - (i / 2) - 1;
        tot += (oth.sum(n) - oth.sum(m) - abv*(abv + 1)/2 - abv*m);
        //cout << m << " " << bel << " " << abv << " " << tot << endl;
        cout << tot + ans << " ";
    }
    cout << '\n';
}