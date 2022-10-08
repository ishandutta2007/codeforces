#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

map<int, vector<int> > A;
int h;
bool F;
map<int, int> d;

#define out(x) {printf ("! %d\n", x); fflush(stdout);}

void ask(int x) {
	printf ("? %d\n", x);
	fflush(stdout);
	int c;
	cin >> c;
	vector<int> B;
	for (int i = 0; i < c; i ++) {
		int x;
		cin >> x;
		B.pb(x);
	}
	random_shuffle(B.begin(), B.end());
	A[x] = B;
}

bool has(int x) {
	return A.find(x) != A.end();
}

bool chk(int x) {
	return has(x) && (int) A[x].size() == 2;
}

int ff(int x) {
	for (int i = 0; i < (int) A[x].size(); i ++)
		if (!has(A[x][i])) return A[x][i];
	return -1;
}

int main() {
	srand(time(NULL));
	int _; cin >> _;
	while (_--) {
		cin >> h;
		A.clear();
		d.clear();
		F = false;
		
		int cur = 1;
		ask(cur);
		
		if (chk(cur)) {
			out(cur);
			continue;
		}
		if ((int) A[cur].size() == 1) {
			d[cur] = 0;
		}
		
		if ((int) A[cur].size() == 3) {
			vector<int> A0, A1;
			int w = A[cur][0];
			while (true) {
				A0.pb(w);
				ask(w);
				if (chk(w)) {
					out(w);
					F = true;
					break;
				}
				if ((int) A[w].size() == 1) break;
				w = ff(w);
			}
			if (F) continue;
			w = A[cur][1];
			while (true) {
				A1.pb(w);
				ask(w);
				if (chk(w)) {
					out(w);
					F = true;
					break;
				}
				if ((int) A[w].size() == 1) break;
				w = ff(w);
			}
			if (F) continue;
			reverse(A0.begin(), A0.end());
			A0.pb(cur);
			for (int i = 0; i < (int) A1.size(); i ++)
				A0.pb(A1[i]);
			int l = (int) A0.size();
			cur = A0[l/2];
			d[cur] = l/2;
		}
		while (true) {
			if (d[cur] == h-2) {
				out(ff(cur));
				break;
			}
			if (d[cur] == h-3) {
				int w = ff(cur);
				ask(w);
				int w1 = ff(w);
				ask(w1);
				if (chk(w1)) {
					out(w1);
				} else {
					out(ff(w));
				}
				break;
			}
			if (h == 7 && d[cur] == 3) {
				int w = ff(cur);
				ask(w);
				if (chk(w)) {
					out(w);
					break;
				}
				int w1 = ff(w);
				ask(w1);
				if (chk(w1)) {
					out(w1);
					break;
				}
				int w2 = ff(w);
				ask(w2);
				if (chk(w2)) {
					out(w2);
					break;
				}
				int w11 = ff(w1);
				ask(w11);
				if (chk(w11)) {
					out(w11);
					break;
				}
				int w12 = ff(w1);
				ask(w12);
				if (chk(w12)) {
					out(w12);
					break;
				}
				int w21 = ff(w2);
				ask(w21);
				if (chk(w21)) {
					out(w21);
					break;
				}
				int w22 = ff(w2);
				out(w22);
				break;
			}
			int w = ff(cur);
			vector<int> A0;
			while (true) {
				ask(w);
				A0.pb(w);
				if (chk(w)) {
					out(w);
					F = true;
					break;
				}
				if ((int) A[w].size() == 1) break;
				w = ff(w);
			}
			if (F) break;
			reverse(A0.begin(), A0.end());
			A0.pb(cur);
			int l = d[cur] + (int) A0.size();
			cur = A0[l/2];
			d[cur] = l/2;
		}
	}
	return 0;
}