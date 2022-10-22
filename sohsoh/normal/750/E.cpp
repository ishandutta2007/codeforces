// Sohsoh84 :)))
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

const ll MAXN = 8e5 + 10;
const ll INF = 1e9;

string t = "2017", s;
int n, q;

struct node {
	int val[5][5];

	node() {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				val[i][j] = (i < j ? INF : 0);
	}

	node (node a, node b) {		
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				val[i][j] = INF;
		for (int i = 0; i < 5; i++) {
				for (int j = i; j < 5; j++) { 
				for (int k = j; k < 5; k++) {
					val[i][k] = min(val[i][k], a.val[i][j] + b.val[j][k]);
				}
			}
		}
	}

	node (char c) {	
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				val[i][j] = (i < j ? INF : 0);
		
		for (int i = 0; i < 4; i++) {
			if (t[i] == c) {
				val[i][i] = 1;
				val[i][i + 1] = 0;
			} 
		}

		if (c == '6') {
			val[3][3] = 1; ////
			val[4][4] = 1; ////	
		}
	}	
} sg[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		sg[v] = node(s[l]);
		return;
	}

	int mid = (l + r) >> 1;
	build(l, mid, v << 1);
	build(mid + 1, r, v << 1 | 1);
	sg[v] = node(sg[v << 1], sg[v << 1 | 1]);
}

node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return node();
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return node(query(ql, qr, l, mid, v << 1), 
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q >> s;
	s = "." + s;
	build();

	while (q--) {
		int l, r;
		cin >> l >> r;

		int ans = query(l, r).val[0][4];
		cout << (ans <= n ? ans : -1) << endl;
	}
	return 0;
}