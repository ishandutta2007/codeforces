#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

ll vq = -1;

ll query(vector <ll> &a, ll l = -1, ll r = -1, ll wi = -1) {
    ll n = a.size();
    if (l == -1) {
        l = 0, r = n - 1;
    }
    ll m = r - l + 1;
    if (wi != -1) {
        m--;
    }
    if (vq != -1) {
        m++;
    }
    if (!m) return 0;
    cout << "? " << m << endl;
    if (vq != -1) {
        cout << vq + 1 << " ";
    }
    for (ll i = l; i <= r; i++) {
        if (wi != -1 && i == wi) {
            continue;
        }
        cout << a[i] + 1 << " ";
    }
    cout << endl;
    ll cnt;
    cin >> cnt;
    return cnt;
}

vector <ll> path, used;
vector <vector <ll> > gr;

bool dfs(ll v, ll t) {
    //cout << v << " ";
    if (used[v]) return false;
    used[v] = true;
    path.push_back(v);
    if (v == t) {
        return true;
    }
    for (ll u : gr[v]) {
        if (dfs(u, t)) {
            return true;
        }
    }
    path.pop_back();
}

int main() {
    ll n;
    cin >> n;
    used.resize(n, false);
    vector <ll> col(n, -1);
    gr.resize(n);
    queue <ll> q;
    q.push(0);
    used[0] = true;
    col[0] = 0;
    while (q.size()) {
        ll v = q.front();
        q.pop();
        //cout << "VER " << v << endl;
        vector <ll> all;
        for (ll i = 0; i < n; i++) {
            if (used[i]) continue;
            all.push_back(i);
        }
        ll pr = -1;
        vq = v;
        ll qt1 = query(all);
        vq = -1;
        ll qt2 = query(all);
        while (qt1 - qt2 > 0) {
            vq = -1;
            ll l = pr, r = all.size() - 1;
            while (r - l > 1) {
                ll mid = (l + r) / 2;
                vq = v;
                ll q1 = query(all, pr + 1, mid);
                vq = -1;
                ll q2 = query(all, pr + 1, mid);
                if (q1 - q2 != 0) {
                    r = mid;
                } else {
                    l = mid;
                }
                //cout << "seg : " << l << " " << r << "\n";
            }
            //cout << v << " " << all[r] << "\n";
            gr[v].push_back(all[r]);
            gr[all[r]].push_back(v);
            col[all[r]] = 1 - col[v];
            pr = r;
            used[all[r]] = true;
            q.push(all[r]);
            vq = v;
            qt1 = query(all, pr + 1, all.size() - 1);
            vq = -1;
            qt2 = query(all, pr + 1, all.size() - 1);
        }
    }
    vector <ll> a, b;
    for (ll i = 0; i < n; i++) {
        if (!col[i]) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    ll q1 = query(a), q2 = query(b);
    if (!q1 && !q2) {
        cout << "Y " << a.size() << endl;
        for (ll x : a) {
            cout << x + 1 << " ";
        }
        cout << endl;
        return 0;
    }
    if (!q1) {
        swap(a, b);
        swap(q1, q2);
    }
    ll m = a.size();
    ll s = -1;
    for (ll i = 0; i < m; i++) {
        ll q = query(a, 0, m - 1, i);
        if (q != q1) {
            s = a[i];
            break;
        }
    }
    assert(s != -1);
    ll t = -1;
    for (ll i = 0; i < m; i++) {
        if (s == a[i]) continue;
        vector <ll> x = {s, a[i]};
        if (query(x)) {
            t = a[i];
            break;
        }
    }
    //cout << "S T " << s << " " << t << "\n";
    used.clear();
    used.resize(n, false);
    dfs(s, t);
    cout << "N " << path.size() << endl;
    for (ll x : path) {
        cout << x + 1 << " ";
    }
}