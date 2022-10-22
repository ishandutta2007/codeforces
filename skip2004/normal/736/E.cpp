#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin; using std::cout;
const int maxn = 3030;
struct pr {
	int id, score;
	inline pr(int _id = 0, int _score = 0) : id(_id), score(_score) {}
	inline int operator < (const pr & b) const { return score < b.score; }
};
pr a[maxn];
char w[maxn][maxn];
int n, m;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> m >> n;
	int score = m * (m - 1);
	rep(i, 1, n) {
		cin >> a[i].score;
		a[i].id = i;
		score -= a[i].score;
	}
	rep(i, 1, m) w[i][i] = 'X';
	if(n != m) {
		const int average = score / (m - n), remain = score % (m - n);
		rep(i, n + 1, m) {
			a[i] = pr(i, average + (i <= n + remain));
		}
	}
	n = m;
	std::reverse(a + 1, a + n + 1);
	if(!std::is_sorted(a + 1, a + n + 1)) {
		cout << "no" << '\n';
		return 0;
	}
	for(int i = n;i >= 1;--i) {
		std::sort(a + 1, a + i + 1);
		for(int j = 1;j < i;++j) {
			if(a[i].score > 1) {
				a[i].score -= 2;
				w[a[i].id][a[j].id] = 'W';
				w[a[j].id][a[i].id] = 'L';
			} else {
				if(a[i].score > 0) {
					a[i].score -= 1;
					a[j].score -= 1;
					w[a[i].id][a[j].id] = 'D';
					w[a[j].id][a[i].id] = 'D';
				} else {
					a[j].score -= 2;
					w[a[i].id][a[j].id] = 'L';
					w[a[j].id][a[i].id] = 'W';
				}
			} 
		}
		if(a[i].score != 0) {
			cout << "no" << '\n';
			return 0;
		}
	}
	cout << "yes" << '\n';
	rep(i, 1, n) {
		rep(j, 1, n) {
			cout.put(w[i][j]);
		}
		cout.put(10);

	}
}