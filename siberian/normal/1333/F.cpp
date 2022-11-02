#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n;

void read() {
	cin >> n;
}

const int MAXN = 5e5 + 10;
int now[MAXN];
vector<int> have;

vector<int> pr;
int lp[MAXN];

void precalc() {
	for (int i = 2; i <= n; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && pr[j] * i <= n; j++) {
			lp[pr[j] * i] = pr[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		now[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (lp[i] == i)
		for (int j = i, cnt = 0; j <= n; j += i, cnt++) {
			chkmax(now[j], cnt);
		}
	}
	have.resize(n);
	iota(all(have), 1);
	sort(all(have), [&] (int a, int b) {return now[a] < now[b];});
}


int cnt[MAXN];
int fans = 1;


void gen(vector<pair<int, int>> & have, int pos, int now) {
	if (pos == (int)have.size()) {
		cnt[now]++;
		if (cnt[now] > 1) {
			chkmax(fans, now);
		}
		return;
	}
	gen(have, pos + 1, now);
	for (int i = 1; i <= have[pos].second; i++) {
		now *= have[pos].first;
		gen(have, pos + 1, now);
	}
}

void get_d(int x) {
	vector<pair<int, int>> have;
	while (x > 1) {
		if (have.empty() || have.back().first != lp[x]) {
			have.push_back({lp[x], 0});
		}
		have[have.size() - 1].second++;
		x /= lp[x];
	}
	gen(have, 0, 1);
}

void add(int x) {
	get_d(x);
}	

int get() {
	return fans;
}

void calc() {
	add(have[0]);
	for (int i = 1; i < n; i++) {
		add(have[i]);
		cout << get() << " ";
	}	
}

void run() {
	precalc();
	calc();
}

void write() {
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}

/*
10

out = 
1 1 1 1 2 3 5 5 5 

ans = 
1 1 1 1 2 3 3 4 5

*/