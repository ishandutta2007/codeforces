#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct seg {
    int l, r, c;
    bool operator< (const seg& o) const { return tie(l, r) < tie(o.l, o.r); }
};

const int MAX = 3e5 + 5, INF = 1e9 + 5;
set<seg> segs;
ll bit[MAX];
vector<ii> upds[MAX];
int cnt[MAX];

void upd(int p, ll v) {
	if(p == 0)
		return;
	for(; p < MAX; p += (p & -p))
		bit[p] += v;
}

ll sum(int p) {
	ll res = 0;
	for(; p; p -= (p & -p))
		res += bit[p];
	return res;
}

int ssum, gl, gr;

void add_seg(int l, int r, int c) {
    vector<seg> rem, add;
    auto it = segs.upper_bound({r + 1, 0, 0});
    --it;
    while(it->r >= l) {
        //cout << it->l << " " << it->r << endl;
        rem.push_back(*it);
        cnt[it->c] -= (it->r - it->l + 1);
        int tot = it->r - it->l + 1;
        if(it->l < l) {
            add.push_back({it->l, l - 1, it->c});
            tot -= l - it->l;
        }
        if(it->r > r) {
            add.push_back({r + 1, it->r, it->c});
            tot -= it->r - r;
        }
        upds[c].push_back({it->c + 1, tot});
        if(it == segs.begin()) break;
        --it;
    }
    add.push_back({l, r, c});
    while(rem.size()) {
        auto s = rem.back(); rem.pop_back();
        segs.erase(s);
    }
    while(add.size()) {
        auto s = add.back(); add.pop_back();
        segs.insert(s);
        cnt[s.c] += (s.r - s.l + 1);
    }
}

int n, k, tot;
ll res;
vector<ii> ivs;

void precalc() {
	segs.insert({1, INF, 0});
	cnt[0] = INF;
	for(int i = 0; i < n; i++)
		add_seg(ivs[i].first, ivs[i].second, i + 1);
}

int pos[MAX], ex[MAX];

bool can(int m) {
    memset(ex, 0, sizeof ex);
    int l = 0, tot = 0;
    ll cur = 0;
    for(int i = 1; i <= n; i++) {
        for(auto u : upds[i]) {
            if(u.first <= l)
                cur += u.second;
            else
                ex[u.first] += u.second;
            ex[i + 1] -= u.second;
            //if(m==4)
            //    cout << "update " << u.first << " " << i << " " << u.second << endl;
        }
        while(cur + ex[l + 1] >= m) {
            l++;
            cur += ex[l];
        }
        pos[i] = l;
        tot += l;
        //if(m == 4)
        //    cout << "tot = " << tot << endl;
        if(tot >= k)
            return false;
    }
    return true;
}

void trace(int m) {
    can(m);
    memset(bit, 0, sizeof bit);
    memset(cnt, 0, sizeof cnt);
    cnt[0] = 1e9;
    int l = 0;
    ll cur = 0;
    for(int i = 1; i <= n; i++) {
        for(auto u : upds[i]) {
            int x = u.first - 1;
            upd(x, (ll)(-x) * u.second);
            cnt[x] -= u.second;
            if(l < x && x <= i)
                cur -= u.second;
            upd(i, (ll)i * u.second);
            cnt[i] += u.second;
        }
        cur += cnt[i];
        while(l < pos[i]) {
            l++;
            cur -= cnt[l];
        }
        //cout << pos[i] << " " << i << " " << cur << endl;
        tot += pos[i];
        res += cur * l;
        res += sum(l);
        //cout << res << " " << tot << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		ivs.push_back({l, r - 1});
	}
    precalc();
	int lo = 0, hi = INF;
	while(lo < hi) {
		int mi = (lo + hi)/2;
		if(can(mi))
			hi = mi;
		else
			lo = mi + 1;
	}
	//cout << lo << endl;
    trace(lo);
	cout << res + (ll)(k - tot) * (lo - 1) << '\n';
}