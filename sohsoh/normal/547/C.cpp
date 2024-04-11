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

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353;

int SPF[MAXN], n, q, cnt_div[MAXN], A[MAXN];
vector<pair<int, bool>> A_List[MAXN];
ll ans = 0;
bool is_in[MAXN];

inline void Prep() {
	for (int i = 1; i < MAXN; i++) SPF[i] = i;
	for (int i = 2; i < MAXN; i++) 
		if (SPF[i] == i) 
			for (int j = 2 * i; j < MAXN; j += i)
				if (SPF[j] == j)
					SPF[j] = i;
}

vector<pair<int, bool>> P_List(int n) {
	int lst = 0;
	vector<pair<int, bool>> ans = {{1, false}};
	while (n > 1) {
		int s = SPF[n];
		n = n / s;
		if (s == lst) continue;
		lst = s;
		int ans_s = ans.size();
		for (int i = 0; i < ans_s; i++) ans.push_back({ans[i].X * s, !ans[i].Y});
	}

	return ans;
}

inline ll Delta(int i) {
	ll ans = 0;
	for (pair<int, bool> e : A_List[i]) {
		if (e.Y) ans -= cnt_div[e.X];
		else ans += cnt_div[e.X];
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Prep();
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		A_List[i] = P_List(A[i]);
	}

	while (q--) {
		int ind;
		cin >> ind;
		if (!is_in[ind]) {
			ans += Delta(ind);
			for (pair<int, bool> e : A_List[ind]) cnt_div[e.X]++;
		} else {	
			for (pair<int, bool> e : A_List[ind]) cnt_div[e.X]--;
			ans -= Delta(ind);
		}
	
		is_in[ind] = !is_in[ind];
		cout << ans << endl;
	}
	return 0;
}