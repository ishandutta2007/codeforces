#include <bits/stdc++.h>
#define ll long long
#define Q __int128_t
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

class NTT{
public:
	#define db long double 
	#define ll long long
	const static int mod = 998244353;
	const static int root = 646; // 646^(2^20) == 1 (998244353)
	const static int rev_root = 208611436;
	const static int MAX_SIZE = 1 << 21;

	void add(int &a, int b){
		a += b;
		if (a < 0) a += mod;
		if (a >= mod) a -= mod;
	}

	int sum(int a, int b){
		add(a, b);
		return a;
	}

	int mult(int a, int b){
		return a * (ll)b % mod;
	}

	int bp(int a, int k){
		if (k == 0) return 1;
		if (k & 1){
			return mult(a, bp(a, k - 1));
		} else {
			int q = bp(a, k >> 1);
			return mult(q, q);
		}
	}

	int rev(int a){
		return bp(a, mod - 2);
	}

	int n;
	int a[MAX_SIZE * 2 + 7], b[MAX_SIZE * 2 + 7];

	int getReverse(int a, int k){
		int ans = 0;
		for (int i = 0; i < k; i++) if ((a >> i) & 1) ans ^= (1 << (k - i - 1));
		return ans;
	}

	void ntt(int *a, int type){
		int k = -1;
		for (int i = 0; i < 25; i++) if ((n >> i) & 1){ 
			k = i;
			break;
		}
		for (int i = 0; i < n; i++){
			int j = getReverse(i, k);
			if (i < j) swap(a[i], a[j]);
		}
		for (int len = 2; len <= n; len *= 2){
			int w = bp(root, (1 << 20) / len);
			if (type == -1) w = bp(rev_root, (1 << 20) / len);
			for (int i = 0; i < n; i += len){
				int g = 1;
				for (int j = 0; j < len / 2; j++){
					int x = a[i + j];
					int y = mult(a[i + j + len / 2], g);
					a[i + j] = sum(x, y);
					a[i + j + len / 2] = sum(x, mod - y);
					g = mult(g, w);
				}
			}
		}
		if (type == -1){ 
			int rev_n = rev(n);
			for (int i = 0; i < n; i++) a[i] = mult(a[i], rev_n);
		}
	}

	vector<int> mult(vector<int> &w1, vector<int> &w2){
		n = 1;
		while(n < w1.size() + w2.size()) n *= 2;
		for (int i = 0; i < w1.size(); i++){
			a[i] = w1[i];
			a[i] %= mod;
			if (a[i] < 0) a[i] += mod;
		}
		for (int i = 0; i < w2.size(); i++){
			b[i] = w2[i];
			b[i] %= mod;
			if (b[i] < 0) b[i] += mod;
		}
		for (int i = w1.size(); i < n; i++) a[i] = 0;
		for (int i = w2.size(); i < n; i++) b[i] = 0;
		ntt(a, 1);
		ntt(b, 1);
		for (int i = 0; i < n; i++) a[i] = mult(a[i], b[i]);
		ntt(a, -1);
		vector<int> ans(n);
		for (int i = 0; i < n; i++) ans[i] = a[i];
		while(ans.size() && ans.back() == 0) ans.pop_back();
		return ans;
	}
};

NTT ntt;


const int MAXN = 1e6 + 7;
const int MOD = 998244353;

vector <int> a;
int n, k;

vector <int> t[MAXN];

void build(int vt = 1, int lt = 0, int rt = n) {
	//cout << vt << " " << lt << " " << rt << endl;
	if (rt - lt == 1) {
		t[vt] = vector <int> ({1, (2 * MOD - a[lt]) % MOD});
		return;
	}
	int mt = (lt + rt) / 2;
	build(2 * vt, lt, mt);
	build(2 * vt + 1, mt, rt);
	t[vt] = ntt.mult(t[2 * vt], t[2 * vt + 1]);
	while (t[vt].size() > rt - lt + 1) t[vt].pop_back();
}

int power(int a, int k) {
	if (!k) return 1;
	int b = power(a, k / 2);
	b = b * (ll) b % MOD;
	if (k % 2) {
		return a * (ll) b % MOD;
	} else {
		return b;
	}
}

int rev(int a) {
	return power(a, MOD - 2);
}

int f[MAXN], rf[MAXN];

void init() {
	f[0] = 1, rf[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		f[i] = f[i - 1] * (ll) i % MOD;
		rf[i] = rev(f[i]);
	}
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * (ll) rf[k] % MOD * rf[n - k] % MOD;
}

vector <int> get(int l, int r, int q, int vt = 1, int lt = 0, int rt = n) {
	if (l >= rt || lt >= r) {
		return {1};
	}
	if (l <= lt && rt <= r) {
		int sz = rt - lt;
		int now = 1;
		vector <int> d;
		auto e = t[vt];
		for (int i = 0; i <= min(sz, (int) e.size() - 1); i++) {
			e[i] = e[i] * (ll) f[sz - i] % MOD;
		}
		for (int i = 0; i <= sz; i++) {
			d.push_back(now * (ll) rf[i] % MOD);
			now = now * (ll) q % MOD;
		}
		auto ret = ntt.mult(d, e);
		while (ret.size() > sz + 1) ret.pop_back();
		for (ll i = 0; i <= sz; i++) {
			ret[i] = ret[i] * (ll) rf[sz - i] % MOD;
		}
		//cout << lt << " " << rt << " " << ret[2] << "\n";
		return ret;
	}
	int mt = (lt + rt) / 2;
	auto xt = get(l, r, q, 2 * vt, lt, mt);
	auto yt = get(l, r, q, 2 * vt + 1, mt, rt);
	return ntt.mult(xt, yt);
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	init();
	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	build();

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int q, p, d;
			cin >> q >> p >> d;
			p--;
			auto ax = get(0, p, q);
			auto az = get(p + 1, n, q);
			auto ay = vector <int> ({1, (2LL * MOD + q - d) % MOD});
			auto dt = ntt.mult(ay, az);
			auto rt = ntt.mult(ax, dt);
			cout << rt[k] << "\n"; 
		} else {
			int q, l, r, d;
			cin >> q >> l >> r >> d;
			l--, r--;
			auto ax = get(0, l, q);
			auto ay = get(l, r + 1, q - d);
			auto az = get(r + 1, n, q);
			auto dt = ntt.mult(ay, az);
			auto rt = ntt.mult(ax, dt);
			cout << rt[k] << "\n"; 
		}
	}
}