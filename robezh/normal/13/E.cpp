#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int B = 200, N = (int)1e5 + 50;

struct edge {
    int to, c;
} e[N];

int n;
int a[N];

void rebuild(int b) {
    for(int i = min((b + 1) * B - 1, n - 1); i >= b * B; i--) {
        int nxt = i + a[i];
        if(nxt >= n) e[i] = {i + n, 0};
        else if(nxt / B > b) e[i] = {nxt, 1};
        else e[i] = {e[nxt].to, e[nxt].c + 1};
    }
}

void answer(int x) {
    int cost = 0;
    while(x < n) {
        cost += e[x].c;
        x = e[x].to;
    }
    cout << x - n + 1 << " " << cost + 1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    for(int i = 0; i <= (n - 1) / B; i++) rebuild(i);

    while(q--) {
        int tp;
        cin >> tp;
        if(tp == 0) {
            int pos, b; cin >> pos >> b; pos--;
            a[pos] = b;
            rebuild(pos / B);
        } else {
            int x; cin >> x; x--;
            answer(x);
        }
    }


}