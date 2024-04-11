#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int a, b, c;


bool form(int x, int y, int z) {
    if(x == y || y == z || x == z) return true;
    if(y < z) swap(y, z);
    return x == max(x, max(y, z)) && x - y == y - z;
}

void answer(int x) {
    cout << x << endl;
    fflush(stdout);
}

mt19937 rng(233);

int ask(ll v) {
    cout << v << endl;
    fflush(stdout);
    int pl; cin >> pl;
    return pl;
}

int main() {
    vl x(3);
    cin >> x[0] >> x[1] >> x[2];
    cout << "First" << endl;
    fflush(stdout);

    int la = 0;
    while(true) {
        vl v = x;
        sort(all(v));
        int p = ask(v[2] * 2 - v[1] - v[0]);
        bool large = (x[p - 1] == v[2]);
        x[p - 1] += v[2] * 2 - v[1] - v[0];
        if(large) continue;
        v = x;
        sort(all(v));
        assert(v[2] - v[1] == v[1] - v[0]);
        p = ask(v[2] - v[1]);
        if(p == 0) break;
    }

}