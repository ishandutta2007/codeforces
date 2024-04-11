#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;

ull modmul(ull a, ull b, ull M) {
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}
ull modpow(ull b, ull e, ull mod) {
    ull ans = 1;
    for(; e; b = modmul(b, b, mod), e /= 2)
        if(e & 1) ans = modmul(ans, b, mod);
    return ans;
}

bool IsP[1000000];

void initialize() {
    for(int i = 2; i < 1e6; i++) IsP[i] = true;
    for(int i = 2; i < 1e6; i++) {
        if(!IsP[i]) continue;
        for(int j = 2 * i; j < 1e6; j += i) {
            IsP[j] = false;
        }
    }
}

bool IsPrime(ull n) {
    if(n < 1e6) return IsP[n];
    if(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    ull A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    ull s = __builtin_ctzll(n - 1), d = n >> s;
    for(ull a : A) {
        ull p = modpow(a % n, d, n), i = s;
        while(p != 1 and p != n - 1 and a % n and i--) {
            p = modmul(p, p, n);
        }
        if(p != n - 1 and i != s) return 0;
    }
    return 1;
}

ll powofprime(ll x) {
    if(IsPrime(x)) return x;
    ll y = sqrt(x);
    for(ll i = y - 1; i <= y + 1; i++) {
        if(1 <= i and i * i == x and IsPrime(i)) return i;
    }
    y = pow(x, 1.0 / 3);
    for(ll i = y - 1; i <= y + 1; i++) {
        if(1 <= i and i * i * i == x and IsPrime(i)) return i;
    }
    for(ll i = 2; i * i * i * i <= x; i++) {
        ll copy = x;
        while(copy % i == 0) copy /= i;
        if(copy != 1) continue;
        if(IsPrime(i)) return i;
    }
    return -1;
}

vector<ll> a;
vector<ll> p;
vector<ll> d;
map<ll, vector<ll>> mp;
vector<ll> ans;
ll N, K;

void solve1() {
    assert(K % 2 == 1);
    for(auto val : d) {
        set<ll> st;
        ll copy = val;
        for(auto tmp : p) {
            if(copy % tmp != 0) continue;
            st.insert(tmp);
            while(copy % tmp == 0) copy /= tmp;
        }
        if(copy != 1) continue;
        if(st.size() * 2 + 1 > K) continue;
        for(auto tmp : p) {
            if(st.size() * 2 + 1 == K) break;
            st.insert(tmp);
        }
        for(auto tmp : st) {
            for(auto val : mp[tmp]) ans.push_back(val);
        }
        ans.push_back(val);
        return;
    }
}

void solve2() {
    for(auto tmp : p) {
        for(auto val : mp[tmp]) {
            ans.push_back(val);
        }
    }
    for(auto val : d) {
        auto copy = val;
        for(auto tmp : p) {
            while(copy % tmp == 0) copy /= tmp;
        }
        if(copy == 1) ans.push_back(val);
    }
    if(ans.size() > K) ans.resize(K);
}

const ll INF = 1e18;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    initialize();
    cin >> N >> K;
    //N = 1000;
    //K = 1000;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    //for(int i = 0; i < N; i++) a[i] = INF - i;
    for(int i = 0; i < N; i++) {
        //cerr << i << endl;
        auto tmp = powofprime(a[i]);
        if(tmp != -1 and mp[tmp].size() <= 1) {
            mp[tmp].push_back(a[i]);
        } else {
            d.push_back(a[i]);
        }
    }
    for(auto tmp : mp) {
        auto v = tmp.second;
        if(v.size() <= 1) continue;
        p.push_back(tmp.first);
    }
    if(2 * p.size() > K and K % 2 == 1) {
        //cerr << "A" << endl;
        solve1();
    } else {
        //cerr << "B" << endl;
        solve2();
    }
    if(ans.size() < K) {
        cout << 0 << endl;
    } else {
        assert(ans.size() == K);
        sort(ans.begin(), ans.end());
        /*
        for(auto tmp : ans) cerr << tmp << " ";
        cerr << endl;
        */
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) {
                assert(ans[i] > ans[i-1]);
                cout << " ";
            }
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}