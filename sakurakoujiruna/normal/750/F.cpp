#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = (1 << 7); 
bool v[N];
vector <int> his[N];

vector <int> nb(int x) {
	if(v[x]) return his[x];
	v[x] = 1;
	printf("? %d\n", x);
	fflush(stdout);
	int k; scanf("%d", &k);
	while(k --) {
		int i; scanf("%d", &i);
		his[x].pb(i);
	}
	return his[x];
}

void ans(int x) {
	printf("! %d\n", x);
	fflush(stdout);
}

int nxt(int x) {
	for(int i = 0; i < 3; i ++)
		if(!v[nb(x)[i]]) return nb(x)[i];
}

void solve(int h) {
	memset(v, 0, sizeof v);
	for(int i = 0; i < N; i ++)
		his[i].clear();
	deque <int> deq = {1};
	if(nb(1).size() == 2) {
		ans(1); return;
	}
	int x = nb(1)[0];
	while(1) {
		deq.push_front(x);
		if(nb(x).size() == 1) break;
		if(nb(x).size() == 2) {
			ans(x); return;
		}
		x = nxt(x);
	}
	//cout << "!!\n";
	if(nb(1).size() > 1) {
		int x = nb(1)[1];
		while(1) {
			deq.push_back(x);
			if(nb(x).size() == 1) break;
			if(nb(x).size() == 2) {
				ans(x); return;
			}
			x = nxt(x);
		}
	}
	//cout << "!!\n";
	while((int)deq.size() < 2 * (h - 3) - 1) {
		int th = (deq.size() + 1) / 2;
		while(deq.size() > th) deq.pop_back();
		int x = nxt(deq.back());
		while(1) {
			deq.push_back(x);
			if(nb(x).size() == 1) break;
			if(nb(x).size() == 2) {
				ans(x); return;
			}
			x = nxt(x);
		}
	}
	//cout << "!!\n";
	//for(int x : deq) cout << x << ' '; cout << '\n';

	int th = (deq.size() + 1) / 2;
	int d = h - th, up = nxt(deq[th - 1]);
	if(d == 1) ans(up);
	if(d == 2) {
		int a = nxt(up); nb(a);
		int b = nxt(up);
		if(nb(a).size() == 2) ans(a);
		else ans(b);
	}
	if(d == 3) {
		int a = nxt(up); nb(a);
		int b = nxt(up);

		int a1 = nxt(a); nb(a1);
		int a2 = nxt(a);
		int b1 = nxt(b); nb(b1);
		int b2 = nxt(b);
		if(nb(a1).size() == 2) ans(a1);
		else if(nb(a2).size() == 2) ans(a2);
		else if(nb(b1).size() == 2) ans(b1);
		else ans(b2);
	}
}

int main() {
	int t; cin >> t;
	while(t --) {
		int h; scanf("%d", &h);
		solve(h);
	}
}