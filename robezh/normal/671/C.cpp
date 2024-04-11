#include <bits/stdc++.h>
using namespace std;

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

int n;
int a[N];
vi dvs[N];
int l1[N], l2[N], r1[N], r2[N];
int la[N];

struct P {
    int l, val;
};

map<int, P> mp;
ll sum = 0;
vector<pii> up[N];

void split(int x) {
    auto it = mp.lower_bound(x);
    if(it -> second.l == x) return ;
    int r1 = it->first, l0 = it->second.l, val = it->second.val;
    mp[r1] = {x, val};
    mp[x - 1] = {l0, val};
}

void update(int pos, int val) {
//    cout << "update " << pos << ", " << val << endl;
    split(pos);
    int r = pos - 1;
    for (auto it = mp.lower_bound(pos); it != mp.end() && it -> second.val < val;) {
        r = it -> first;
        sum -= 1LL * (r - it->second.l + 1) * it->second.val;
        it = mp.erase(it);
    }
    if(pos <= r) {
        mp[r] = {pos, val};
        sum += 1LL * (r - pos + 1) * val;
    }


//    cout << "in map" << endl;
//    for (auto p : mp) cout << "[" << p.second.l << ", " << p.first << "]: " << p.second.val << endl;
}

void pop_end(int pos) {
    assert(!mp.empty());
    split(pos);
    auto it = mp.end(); it--;
    sum -= it->second.val;
    mp.erase(it);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    rep(i, 1, N) for (int j = i; j < N; j += i) dvs[j].push_back(i);
    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];


    memset(l1, -1, sizeof(l1));
    memset(l2, -1, sizeof(l2));
    memset(r1, -1, sizeof(r1));
    memset(r2, -1, sizeof(r2));
    rep(i, 1, n + 1) {
        for (int d : dvs[a[i]]) {
            if(l1[d] == -1) l1[d] = i;
            else if(l2[d] == -1) l2[d] = i;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int d : dvs[a[i]]) {
            if(r1[d] == -1) r1[d] = i;
            else if(r2[d] == -1) r2[d] = i;
        }
    }
    mp[n] = {0, 1};
    sum = n + 1;

    rep(d, 1, N) {
        if(l2[d] == -1) continue;
        up[n + 1].push_back({l2[d], d});
        up[r1[d]].push_back({l1[d], d});
        up[r2[d]].push_back({0, d});
    }
    ll res = 0;
    for (int i = n + 1; i >= 2; i--) {
        for (auto p : up[i]) {
            update(p.first, p.second);
        }

        pop_end(i - 1);
        res += sum;
//        cout << "sum:  " << sum << endl;
    }

    cout << res - (n == 1 ? 1 : 3) << endl;

}