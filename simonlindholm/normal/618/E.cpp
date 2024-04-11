#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

static char buf[200<<20] alignas(16);
struct Small {
	void* operator new(size_t s) {
		static size_t i = 0;
		return (void*)&buf[i += s];
	}
};
struct Tr : Small {
	double dx, dy;
	int ang;
	Tr *par, *left, *right;
	Tr(int n, int ind, vector<Tr*>& out, Tr* par) : par(par) {
		dy = 0;
		ang = 0;
		dx = n;
		if (n == 1) {
			left = right = 0;
			out[ind] = this;
		}
		else {
			int half = n/2;
			left = new Tr(half, ind, out, this);
			right = new Tr(n-half, ind+half, out, this);
		}
	}

	void update() {
		if (left) {
			double ang1 = left->ang * (acos(0) / 90);
			dx = left->dx + right->dx * cos(ang1) - right->dy * sin(ang1);
			dy = left->dy + right->dy * cos(ang1) + right->dx * sin(ang1);
			ang = (left->ang + right->ang) % 360;
		}
		if (par) par->update();
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<Tr*> out(N+1);
	Tr* tr = new Tr(N+1, 0, out, 0);
	cout << setprecision(10) << fixed;
	rep(i,0,M) {
		int t, ind, val;
		cin >> t >> ind >> val;
		if (t == 1) {
			out[ind]->dx += val;
			out[ind]->update();
		}
		else {
			out[ind-1]->ang = (out[ind-1]->ang - val) % 360;
			out[ind-1]->update();
		}
		cout << tr->dx-1 << ' ' << tr->dy << '\n';
	}
}