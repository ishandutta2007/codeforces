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

const int maxn = 2e5 + 100, maxw = (1 << 19) + 10, inf = 1e9 + 100, mod = 1e9 + 993;

struct seg_tree{
    vector<int> q;
    vector<ll> p;

    void build(int n){
        q.resize(4 * n);
        p.resize(4 * n);
    }

    int get(int v, int l, int r, int id){
        if (id == 0)
            return -1;
        if (l == r)
            return l;
        int m = (l + r) / 2;
        if (q[2 * v] >= id)
            return get(2 * v, l, m, id);
        return get(2 * v + 1, m + 1, r, id - q[2 * v]);
    }

    ll get(int v, int tl, int tr, int l, int r){
        if (l > r)
            return 0;
        if (tl == l && tr == r)
            return p[v];
        int m = (tl + tr) / 2;
        return get(2 * v, tl, m, l, min(r, m)) + get(2 * v + 1, m + 1, tr, max(l, m + 1), r);
    }

    void update(int v, int l, int r, int id, int val){
        if (l == r){
            q[v] = (val > 0);
            p[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (id <= m)
            update(2 * v, l, m, id, val);
        else
            update(2 * v + 1, m + 1, r, id, val);
        q[v] = q[2 * v] + q[2 * v + 1];
        p[v] = p[2 * v] + p[2 * v + 1];
    }

    int solve(int n, int k, ll t){
        while (1){
            int cnt = q[1];
            if (cnt == 0)
                break;
            int r = cnt % k;
            if (r == 0)
                r = k;
            int pos = get(1, 0, n - 1, cnt - r);
            ll val = get(1, 0, n - 1, 0, pos);
            if (p[1] + val <= t)
                break;
            pos = get(1, 0, n - 1, cnt);
            update(1, 0, n - 1, pos, 0);
        }
        return q[1];
    }

};

pair<int, int> mas[maxn];

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
    int tst;
    cin >> tst;
    while (tst--){
        int n, m;
        ll t;
        cin >> n >> m >> t;
        for (int i = 0; i < n; i++)
            cin >> mas[i].fr, mas[i].sc = i;
        sort(mas, mas + n);
        int ans = 0, anst = 1;
        seg_tree q;
        q.build(n);
        for (int i = 0; i < n && mas[i].fr <= t; i++){
            q.update(1, 0, n - 1, mas[i].sc, mas[i].fr);
            if (i == n - 1 || mas[i].fr != mas[i + 1].fr){
                int now = q.solve(n, m, t);
                if (now > ans)
                    ans = now, anst = mas[i].fr;
            }
        }
        cout << ans << ' ' << anst << '\n';
    }
}