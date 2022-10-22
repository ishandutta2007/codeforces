#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;

vector <vector <ll> > binup, sumup;
vector <ll> w;
ll lst = 1;

void add(ll v, ll w1) {
    ll u = lst++;
    w.push_back(w1);
    if (w[v] < w[u]) {
        for (ll i = LOGN - 1; i >= 0; i--) {
            if (binup[v][i] == -1 || w[binup[v][i]] >= w1) continue;
            v = binup[v][i];
        }
        v = binup[v][0];
    }
    //cout << "KEKOS " << u << " " << v << "\n";
    binup.push_back(vector <ll> (LOGN, -1));
    sumup.push_back(vector <ll> (LOGN, -1));
    if (v == -1) {
        return;
    }
    binup[u][0] = v;
    sumup[u][0] = w[v];
    for (ll i = 1; i < LOGN; i++) {
        if (binup[u][i - 1] == -1) break;
        ll x = binup[u][i - 1];
        binup[u][i] = binup[x][i - 1];
        sumup[u][i] = sumup[u][i - 1] + sumup[x][i - 1];
    }
}

int get(ll v, ll x) {
    if (x < w[v]) {
        return 0;
    }
    ll res = 1;
    x -= w[v];
    for (ll i = LOGN - 1; i >= 0; i--) {
        if (binup[v][i] == -1) continue;
        if (sumup[v][i] > x) continue;
        x -= sumup[v][i];
        res += (1 << i);
        v = binup[v][i];
    }
    return res;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    binup.push_back(vector <ll> (LOGN, -1));
    sumup.push_back(vector <ll> (LOGN, -1));
    w.push_back(0);
    ll Q;
    cin >> Q;
    ll last = 0;
    for (ll i = 0; i < Q; i++) {
        ll t, p, q;
        cin >> t >> p >> q;
        p ^= last, q ^= last;
        p--;
        //cout << t << " " << p << " " << q << "\n";
        if (t == 1) {
            add(p, q);
        } else {
            last = get(p, q);
            cout << last << "\n";
        }
    }
}