#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
//const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(7476);

vector<int> d[N];
vector<int> inv[N];
vector<int> a[N];
vector<li> p[N];

int l = 1, r = 0;
li res = 0;

void addr(int i) {
    int cnt = d[i].size() - (lower_bound(d[i].begin(), d[i].end(), l) - d[i].begin());
    res += cnt * 1ll * (cnt - 1) / 2;
    if(i % 3 == 0) {
        if(i / 3 * 2 >= l && i % 2 == 0 && i / 2 >= l)
            res++;
        if(i / 3 * 2 >= l && i % 5 == 0 && i / 5 * 2 >= l)
            res++;
    }
}

void delr(int i) {
    int cnt = d[i].size() - (lower_bound(d[i].begin(), d[i].end(), l) - d[i].begin());
    res -= cnt * 1ll * (cnt - 1) / 2;
    if(i % 3 == 0) {
        if(i / 3 * 2 >= l && i % 2 == 0 && i / 2 >= l)
            res--;
        if(i / 3 * 2 >= l && i % 5 == 0 && i / 5 * 2 >= l)
            res--;
    }
}

void addl(int i) {
//    cout << "addl " << i << endl;
//    cout << p[i].size() << ' ' << upper_bound(inv[i].begin(), inv[i].end(), r) - inv[i].begin() << endl;
    res += p[i][upper_bound(inv[i].begin(), inv[i].end(), r) - inv[i].begin()];

    if(i % 3 == 0) {
        if(i * 2 <= r)
            res++;
        if(i % 2 == 0 && i / 2 * 5 <= r)
            res++;
    }
}

void dell(int i) {
    res -= p[i][upper_bound(inv[i].begin(), inv[i].end(), r) - inv[i].begin()];

    if(i % 3 == 0) {
        if(i * 2 <= r)
            res--;
        if(i % 2 == 0 && i / 2 * 5 <= r)
            res--;
    }
}

pair<pii, int> q[N];
li ans[N];

bool cmp(pair<pii, int> a, pair<pii, int> b) {
    int ba = a.f.f / B;
    int bb = b.f.f / B;

    if(ba != bb)
        return ba < bb;
    else if(ba % 2 == 0)
        return a.f.s < b.f.s;
    else
        return a.f.s > b.f.s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i < N; i++) {
        for(int j = i + i; j < N; j += i) {
            d[j].push_back(i);
            inv[i].push_back(j);
        }
    }

    for(int i = 1; i < N; i++) {
        a[i].resize(inv[i].size());
        p[i].resize(inv[i].size() + 1, 0);
        for(int j = 0; j < inv[i].size(); j++) {
            int x = inv[i][j];
            a[i][j] = d[x].size() - (upper_bound(d[x].begin(), d[x].end(), i) - d[x].begin());
            p[i][j + 1] = p[i][j] + a[i][j];
        }
    }

//    for(int i = 1; i < 30; i++) {
//        cout << i << " : ";
//        for(int x : d[i])
//            cout << x << ' ';
//        cout << endl;
//    }

    int t = 1;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> q[i].f.f >> q[i].f.s;

        q[i].s = i;
    }

    sort(q, q + t, cmp);

    for(int i = 0; i < t; i++) {
        int ql = q[i].f.f, qr = q[i].f.s;
//        cout << i << ' ' << ql << ' ' << qr << endl;

        while(r < qr) {
            addr(++r);
        }
//cout << i << ' ' << ql << ' ' << qr << endl;
        while(l > ql) {
            addl(--l);
        }
//cout << i << ' ' << ql << ' ' << qr << endl;
        while(r > qr) {
            delr(r--);
        }
//cout << i << ' ' << ql << ' ' << qr << endl;
        while(l < ql) {
            dell(l++);
        }
//cout << i << ' ' << ql << ' ' << qr << endl;
        ans[q[i].s] = (r - l + 1) * 1ll * (r - l) * (r - l - 1) / 6 - res;
    }

    for(int i = 0; i < t; i++)
        cout << ans[i] << '\n';
}