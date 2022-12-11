#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
#define low_bo(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define up_bo(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()

using namespace std;

typedef long long ll;

void setmin(int &x, int y){
	x = min(x, y);
}

void setmax(int &x, int y){
	x = max(x, y);
}

void setmin(ll &x, ll y){
	x = min(x, y);
}

void setmax(ll &x, ll y){
	x = max(x, y);
}

const ll llinf = 1e18 + 100;

const int maxn = 1e6 + 100, maxw = (1 << 21) + 10, inf = 1e9 + 100, mod = 1e9 + 993;


struct seg_tree{
    int q[maxw];
    ll u[maxw], p[maxw];

    void build(int v, int l, int r, int k){
        q[v] = r - l + 1;
        u[v] = 0;
        p[v] = k;
        if (l == r)
            return;
        int m = (l + r) / 2;
        build(2 * v, l, m, k);
        build(2 * v + 1, m + 1, r, k);
    }

    void push(int v, int l, int r){
        if (u[v] == 0)
            return;
        p[v] -= u[v];
        if (l != r)
            u[2 * v] += u[v], u[2 * v + 1] += u[v];
        u[v] = 0;
    }

    ll update(int v, int tl, int tr, int l, int r, int core, int cost){
        push(v, tl, tr);
        if (l > r)
            return 0;
        if (tl == l && tr == r){
            ll ans = 0;
            ans += get(v, tl, tr, core, cost);
            u[v] = core;
            push(v, tl, tr);
            return ans + cost * (ll)core * (ll)q[v];
        }
        int m = (tl + tr) / 2;
        ll ans = update(2 * v, tl, m, l, min(r, m), core, cost) +
        update(2 * v + 1, m + 1, tr, max(l, m + 1), r, core, cost);
        q[v] = q[2 * v] + q[2 * v + 1];
        p[v] = min(p[2 * v], p[2 * v + 1]);
        return ans;
    }

    ll get(int v, int l, int r, int core, int cost){
        push(v, l, r);
        if (p[v] > core)
            return 0;
        if (l == r){
            ll ans = p[v] * (ll)cost;
            p[v] = llinf;
            q[v] = 0;
            return ans;
        }
        int m = (l + r) / 2;
        ll ans = get(2 * v, l, m, core, cost) + get(2 * v + 1, m + 1, r, core, cost);
        q[v] = q[2 * v] + q[2 * v + 1];
        p[v] = min(p[2 * v], p[2 * v + 1]);
        return ans;
    }
} q;

pair<pair<int, int>, pair<int, int> > arr[maxn];

int main() {
#ifdef MADE_BY_SERT
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#else
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    q.build(1, 0, n - 1, k);
    for (int i = 0; i < m; i++)
        cin >> arr[i].sc.fr >> arr[i].sc.sc >> arr[i].fr.sc >> arr[i].fr.fr,
        arr[i].sc.fr--, arr[i].sc.sc--;
    sort(arr, arr + m);
    ll ans = 0;
    for (int i = 0; i < m; i++)
        ans += q.update(1, 0, n - 1, arr[i].sc.fr, arr[i].sc.sc, arr[i].fr.sc, arr[i].fr.fr);
    cout << ans;
}