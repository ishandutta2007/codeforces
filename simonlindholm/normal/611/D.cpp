#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll mod = 1000000007;

typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) {
	//this is just 3 times faster than stl sort for N=10^6
	int mask = (1 << bits) - 1;
	rep(it,0,2) {
		int move = it * bits;
		vi q(1 << bits), w(sz(q) + 1);
		rep(i,0,sz(b))
			q[(b[i].first >> move) & mask]++;
		partial_sum(q.begin(), q.end(), w.begin() + 1);
		vector<pli> res(b.size());
		rep(i,0,sz(b))
			res[w[(b[i].first >> move) & mask]++] = b[i];
		swap(b, res);
	}
}
struct SuffixArray {
	vi a;
	string s;
	SuffixArray(const string& _s) : s(_s + '\0') {
		int N = sz(s);
		vector<pli> b(N);
		a.resize(N);
		rep(i,0,N) {
			b[i].first = s[i];
			b[i].second = i;
		}

		int q = 8;
		while ((1 << q) < N) q++;
		for (int moc = 0;; moc++) {
			count_sort(b, q); // sort(all(b)) can be used as well
			a[b[0].second] = 0;
			rep(i,1,N)
				a[b[i].second] = a[b[i - 1].second] +
					(b[i - 1].first != b[i].first);

			if ((1 << moc) >= N) break;
			rep(i,0,N) {
				b[i].first = (ll)a[i] << q;
				if (i + (1 << moc) < N)
					b[i].first += a[i + (1 << moc)];
				b[i].second = i;
			}
		}
		rep(i,0,sz(a)) a[i] = b[i].second;
	}
	vi lcp() {
		// longest common prefixes: res[i] = lcp(a[i], a[i-1])
		int n = sz(a), h = 0;
		vi inv(n), res(n);
		rep(i,0,n) inv[a[i]] = i;
		rep(i,0,n) if (inv[i] > 0) {
			int p0 = a[inv[i] - 1];
			while (s[i + h] == s[p0 + h]) h++;
			res[inv[i]] = h;
			if(h > 0) h--;
		}
		return res;
	}
};

const int inf = numeric_limits<int>::max();

template<class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, vector<T>(N));
		jmp[0] = V;
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int main() {
	cin.sync_with_stdio(false);
	int N;
	string str;
	cin >> N;
	cin >> str;
	SuffixArray sa(str);
	vi lcp = sa.lcp(), inv(N+1);
	rep(i,0,N+1) {
		inv[sa.a[i]] = i;
	}
	RMQ<int> rmq(lcp);
	vector<vector<ll> > lengthAtLeast(N, vector<ll>(N+1, 0));
	vector<vector<ll> > lengthExactly(N, vector<ll>(N+1, 0));
	auto incr = [&](int pos, int len) -> bool {
		int p1 = inv[pos];
		int p2 = inv[pos+len];
		if (p1 > p2) return false;
		// return true unless the first len letters match.
		return rmq.query(p1+1, p2+1) < len;
		// return str.substr(pos, len) < str.substr(pos+len, len);
	};
	for (int pos = N-1; pos >= 0; --pos) {
		if (str[pos] == '0') continue; // then 0
		ll sum = 0;
		for (int len = N; len >= 1; --len) {
			if (pos + len > N) continue;
			ll num = (pos + len == N ? 1 : (len+1 > N ? 0 : lengthAtLeast[pos + len][len+1]));
			if (pos + len*2 <= N && incr(pos, len)) {
				num += lengthExactly[pos + len][len];
				if (num > mod) num -= mod;
			}

			lengthExactly[pos][len] = num;
			sum += num;
			if (sum > mod) sum -= mod;
			lengthAtLeast[pos][len] = sum;
		}
	}
	cout << lengthAtLeast[0][1] << endl;
}