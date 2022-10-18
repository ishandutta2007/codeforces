#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define double long double
double A, B, C, D;
#define MUL(A, B, err, op) op(op((A+err) * (B+err), (A-err) * (B-err)), op((A+err) * (B-err), (A-err) * (B+err)))

bool works(double lim) {
	double adlow = MUL(A, D, lim, min);
	double adhigh = MUL(A, D, lim, max);
	double bclow = MUL(B, C, lim, min);
	double bchigh = MUL(B, C, lim, max);
	return adhigh >= bclow && bchigh >= adlow;
}

int main() {
	cin.sync_with_stdio(false);
	cin >> A >> B >> C >> D;
	double low = 0, high = 1.1e9;
	rep(i,0,100) {
		double mid = (low + high) / 2;
		if (works(mid))
			high = mid;
		else
			low = mid;
	}
	cout << setprecision(12) << fixed << low << endl;
}