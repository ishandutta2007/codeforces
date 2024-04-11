#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

struct MajikalStruct {
	bool clear_b[MAXN];
	bool lz[MAXN];
	int A[MAXN], sg[MAXN];

	inline void Push(int v, int L, int R) {
		if (lz[v] != 0) {
			clear_b[v << 1] = false;
			clear_b[v << 1 | 1] = false;
			clear_b[v] = false;
			lz[v << 1] += lz[v];
			lz[v << 1 | 1] += lz[v];
			sg[v] = lz[v] * (R - L + 1);
			lz[v] = 0;
		} else if (clear_b[v]) {
			clear_b[v << 1] = true;
			clear_b[v << 1 | 1] = true;
			clear_b[v] = false;
			sg[v] = 0;
			lz[v << 1] = 0;
			lz[v << 1 | 1] = 0;
		}
	} 

	void Build(int v, int L, int R) {
		if (L == R) sg[v] = A[L];
		else {
			int mid = (L + R) >> 1;
			Build(v << 1, L, mid);
			Build(v << 1 | 1, mid + 1, R);
			sg[v] = sg[v << 1] + sg[v << 1 | 1]; 
		}
	}

	int Query(int v, int L, int R, int ql, int qr) {	
		Push(v, L, R);
		if (ql > qr) return 0;
		if (ql == L && qr == R) return sg[v];

		int mid = (L + R) >> 1;
		return Query(v << 1, L, mid, ql, min(qr, mid)) + Query(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr);
	}

	void Update(int v, int L, int R, int ql, int qr, int val) {	
		Push(v, L, R);
		if (ql > qr) return;
		if (ql == L && qr == R) {
			lz[v] += val; 
			Push(v, L, R);
			return;
		}

		int mid = (L + R) >> 1;
		Update(v << 1, L, mid, ql, min(qr, mid), val);
		Update(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr, val);
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
	}

	void Clear(int v, int L, int R, int ql, int qr) {
		Push(v, L, R);
		if (ql > qr) return;
		if (ql == L && qr == R) {
			lz[v] = 0;
			clear_b[v] = true;
			Push(v, L, R);
			return;
		}
		
		int mid = (L + R) >> 1;
		Clear(v << 1, L, mid, ql, min(qr, mid));
		Clear(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr);
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
	}
};

MajikalStruct Seg[26];
int n, q, A[MAXN], cnt[26];
MajikalStruct seg;

inline void Teest() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> seg.A[i];
	seg.Build(1, 1, n);
	while (true) {
		string s;
		int L, R;
		cin >> s >> L >> R;
		if (s == "Query") cout << seg.Query(1, 1, n, L, R) << endl;
		else if (s == "Clear") seg.Clear(1, 1, n, L, R);
		else if (s == "Update") seg.Update(1, 1, n, L, R, 1);
		else cout << "WTF" << endl;		
	}

	return; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	Teest();

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		A[i] = int(c - 'a');
		Seg[A[i]].A[i] = 1;
	}	

	for (int i = 0; i < 26; i++) Seg[i].Build(1, 1, n);
	
	while (q--) {
		int L, R, k;
		cin >> L >> R >> k;
		vector<int> t;


		for (int i = 0; i < 26; i++) {
			cnt[i] = Seg[i].Query(1, 1, n, L, R);
			Seg[i].Clear(1, 1, n, L, R);	
			t.push_back(i);
		} 

		if (k == 0) reverse(all(t));
		int ind = L;
		for (int e : t) {
			Seg[e].Update(1, 1, n, ind, ind + cnt[e] - 1, 1);
			ind += cnt[e];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < 26; c++) {
			if (Seg[c].Query(1, 1, n, i, i)) {
				cout << char(c + 'a');
				break;
			}
		}
	}

	cout << endl;
	return 0;
}