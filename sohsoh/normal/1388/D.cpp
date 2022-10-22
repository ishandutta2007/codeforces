/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

stack<ll> neg;
ll A[MAXN], in_deg[MAXN] = {0}, n, ans = 0;
ll adj[MAXN];
vector<ll> ans_v;
queue<ll> q;

int main() {
	fast_io;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		adj[i] = x;
		if (x > 0) in_deg[x]++;
	}

	for (int i = 1; i <= n; i++) if (in_deg[i] == 0) q.push(i);
	while (!q.empty()) {
		ll v = q.front();
		ll i = v;
		q.pop();
		if (A[v] < 0) neg.push(v), ans += A[i];
		else {
			ans_v.push_back(v);
			ans += A[i];
			if (adj[i] > 0) {
				A[adj[i]] += A[i];
			}
		}
		
		if (adj[i] > 0) {
			in_deg[adj[i]]--;
			if (in_deg[adj[i]] <= 0) q.push(adj[i]);
		}
	}
	
	cout << ans << endl;
	for (ll e : ans_v) cout << e << sep;
	while (!neg.empty()) {
		cout << neg.top() << sep;
		neg.pop();
	}

	cout << endl;
	return 0;
}