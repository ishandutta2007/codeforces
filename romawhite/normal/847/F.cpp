#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef long long ll;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 707;
const int MOD = 1000000007; 

int cnt[MAX];
int n, k, m, a;

int tmm[MAX];

int try_1(int id) {

	if (cnt[id] == 0)
		return 0;
	if (k == n)
		return 1;
	vector<PII> X;
	FOR(i,0,n) {
		if (i != id)
			X.push_back(MP(cnt[i], -tmm[i]));
	}
	sort(ALL(X));
	reverse(ALL(X));
	int need = 0;
	FOR(i,0,k) {
		if (X[i].first > cnt[id])
			continue;
		if (X[i].first < cnt[id]) {
			need += cnt[id] + 1 - X[i].first;
			continue;
		}
		if (-X[i].second > tmm[id])
			need ++;
	}
	if (need > m)
		return 1;
	return 0;
}

int try_2(int id) {
	int bad = 0;
	FOR(i,0,n) {
		if (i == id)
			continue;
		if (cnt[i] >= cnt[id] + m)
			bad ++;
	}
	if (bad >=k || (m == 0 && cnt[id] == 0))
		return 0;
	return 1;
}

int main(int argc, char* argv[])
{
	ios::sync_with_stdio(false); cin.tie(0);
 
	
	cin >> n >> k >> m >> a;

	FOR(i,0,a) {
		int x;
		cin >> x;
		cnt[x - 1] ++;
		tmm[x - 1] = i;
	}
	m -= a;
	FOR(i,0,n) {
		if (try_1(i)) {
			cout << 1 << ' ';
		} else {
			if (try_2(i)) {
				cout << 2 << ' ';
			} else {
				cout << 3 << ' ';
			}
		}
	}
	

	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}