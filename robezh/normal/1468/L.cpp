#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e3 + 50;
const ll MX = (ll)3e18;

ll getpow(ll x, int k) {
    ll res = 1;
    while(k--) {
        if(res > MX / x) return MX;
        else res *= x;
    }
    return res;
}


ll getroot(int k, ll x) {
    int l = 1, r = (int)1e9 + 50, mid;
    while(l + 1 < r) {
        mid = (l + r) / 2;
        if(getpow(mid, k) <= x) l = mid;
        else r = mid;
    }
    if(getpow(l, k) == x) return l;
    else return -1;
}

bool is_prime(ll x) {
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
    return true;
}

int n, k;
ll x[N];
vector<ll> cnd, pms;
vector<int> idxs[N];
vector<int> mp[N];
int take[N], must[N];

bool good(int j) {
    for(int id : idxs[j]) if(mp[id].empty()) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) {
        cin >> x[i];
        for(int p = 59; p >= 2; p--) {
            ll gr = getroot(p, x[i]);
            if(gr != -1) {
                cnd.push_back(gr);
                break;
            }
        }
    }
    sort(all(cnd));
    cnd.resize(unique(all(cnd)) - cnd.begin());
    for(ll c : cnd) if(is_prime(c)) pms.push_back(c);
    rep(i, 0, n) {
        ll cx = x[i];
        rep(j, 0, sz(pms)) {
            ll p = pms[j];
            if(cx % p == 0) {
                idxs[i].push_back(j);
                while(cx % p == 0) cx /= p;
            }
        }
        if(cx != 1) idxs[i].clear();
    }
//    for(ll p : pms) cout << p << " ";
//    cout << endl;


    rep(i, 0, n) if(idxs[i].size() == 1) mp[idxs[i][0]].push_back(i);
    int sum = 0;
    rep(i, 0, n) {
        if(mp[i].size() == 1) mp[i].clear();
        sum += sz(mp[i]);
//        cout << i << ": " << mp[i].size() << endl;
    }



    if(sum < k) {
        vector<ll> res;
        rep(i, 0, n) for(int id : mp[i]) res.push_back(x[id]);
        rep(i, 0, n) {
            if(idxs[i].size() > 1 && good(i)) res.push_back(x[i]);
        }
        if(sz(res) < k) cout << 0 << '\n';
        else {
            rep(i, 0, k) cout << res[i] << " ";
            cout << '\n';
        }
    } else {
        vi idx;
        ll sum_tk = 0;
        rep(i, 0, n) if(mp[i].size()) idx.push_back(i), sum_tk += sz(mp[i]), take[i] = sz(mp[i]);
        sort(all(idx), [](const int i, const int j) {
            return take[i] < take[j];
        });
        if(take[idx.back()] == 2 && k % 2 == 1) {
//            cout << "case 1" << endl;
            rep(i, 0, n) {
                if(idxs[i].size() >= 2 && sz(idxs[i]) <= k / 2 && good(i)) {
                    for(int id : idxs[i]) {
                        must[id] = 1;
                    }
                    vector<ll> res;
                    res.push_back(x[i]);
                    for(int pt = 1; pt >= 0; pt--) {
                        rep(j, 0, n) if(!mp[j].empty() && must[j] == pt) {
                            res.push_back(x[mp[j][0]]);
                            res.push_back(x[mp[j][1]]);
                        }
                    }
                    rep(j, 0, k) cout << res[j] << " ";
                    cout << '\n';
                    return 0;
                }
            }
            cout << 0 << '\n';
            return 0;

        } else {
//            cout << "case 2" << endl;

            if(k == 1) return cout << 0 << '\n', 0;
            rep(j, 0, sz(idx)) {
                ll rm = sum_tk - max(sum_tk - take[idx[j]], 1LL * k);
                take[idx[j]] -= rm;
                sum_tk -= rm;
                if(take[idx[j]] == 1) {
                    take[idx[j]]++;
                    take[idx.back()]--;
                    break;
                }
            }
            vector<ll> res;
            rep(i, 0, n) {
                rep(j, 0, take[i]) res.push_back(x[mp[i][j]]);
            }
            for(ll y : res) cout << y << " ";
            cout << '\n';

        }
    }


}