#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 53
#define MAXT 5013
int N, R;
int F[MAXN], S[MAXN];
double P[MAXN];
double T[MAXN][MAXT + 100];

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> R;
	for (int i = 0; i < N; i++) {
		cin >> F[i] >> S[i] >> P[i];
		P[i] /= 100.0;
	}

	double lo = 0;
	// Overestimate: 100 * 50 / (0.8 ^ 50)
	double hi = 350324616.08120245;

	// 100 binary search iterations to improve precision
	for (int iter = 0; iter < 100; iter++) {
		double K = (lo + hi) / 2;
		for (int i = 0; i <= N; i++) {
			for (int t = 0; t < MAXT + 100; t++) {
				T[i][t] = K;
			}
		}
		for (int t = 0; t <= R; t++) {
			T[N][t] = 0;
		}
		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < MAXT; j++) {
				double expect = P[i] * (F[i] + T[i + 1][j + F[i]]);
				expect += (1 - P[i]) * (S[i] + T[i + 1][j + S[i]]);
				if (i == 0 && j == 0) T[i][j] = expect;
				else T[i][j] = min(T[i][j], expect);
			}
		}

		if (T[0][0] >= K) {
			// K is too small
			lo = K;
		}
		else {
			hi = K;
		}
	}

	cout << fixed << setprecision(9) << (lo + hi) / 2 << endl;
	
	// cin >> lo;
	// cin >
}