#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 555555;
deque<int> Q;
int Tc, N;
typedef long long LL;
// An efficient logarithmic data structure
int p[MX];
struct BIT {
	int v[MX];
	int n, pw;
	void init(int m) {
		n = m;
		fill_n(v, n + 1, 0);
		for (pw = 1; pw * 2 <= n; pw *= 2);
	}
	void add(int k, int d) {
		for (; k <= n; k += k & -k) v[k] += d;
	}
	int get(int k) {
		int s = 0;
		for (; k > 0; k -= k & -k) s += v[k];
		return s;
	}
} T;
int id[MX];
bool cmp(int x, int y) {
	return p[x] < p[y];
}
map<int,int> H;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int i, j;
	for (cin >> Tc; Tc--; ) {
		while(!Q.empty()) Q.pop_back();
		H.clear();
		LL rlt = 0LL;
		cin >> N;
		for(int i = 0 ; i < N ; i ++) {
			cin >> p[i];
			id[i] = i;
		}
		sort(id, id + N, cmp);
		int cnt = 1;
		for(int i = 0 ; i < N ; i ++) {
			if(H.count(p[id[i]])) continue;
			H[p[id[i]]] = cnt ++;
		}
		T.init(N + 5);
		for(int i = 0 ; i < N ; i ++) {
			int A = T.get(H[p[i]] - 1);
			int B = T.get(H[p[i]]);
			int C = T.get(N);
			T.add(H[p[i]], 1);
			if(A < C - B) Q.push_back(p[i]), rlt += 1LL * A;
			else Q.push_front(p[i]), rlt += 1LL * (C - B);
		}
		cout << rlt << endl;
	}

	return 0;

}