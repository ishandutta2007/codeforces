#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool win(int N, int K, int ones, int zeros, bool w = 1) {
	if (N == K) return (ones & 1);
	if (ones == 0) return win(N-1, K, ones, zeros-1, !w);
	if (zeros == 0) return win(N-1, K, ones-1, zeros, !w);
	int left = N - K;
	if (left == 1) {
		if (w) {
			return ones > 0 && (zeros || ones % 2 == 0);
		}
		else {
			return !(ones == 0 || zeros || ones % 2 == 1);
		}
	}
	else if (left % 2 == 0) {
		// won't have last turn. must end a pile, and only the smallest is viable
		if (ones < zeros)
			return win(N-1, K, ones-1, zeros, !w);
		else
			return win(N-1, K, ones, zeros-1, !w);
	}
	else {
		// will have last turn! must not let a pile end
		if (ones > zeros)
			return win(N-1, K, ones-1, zeros, !w);
		else
			return win(N-1, K, ones, zeros-1, !w);
	}
}

/*
bool win(int N, int K, int ones, int zeros, bool w = 1) {
	if (ones < 0 || zeros < 0) return true;
	if (N == K) return (ones & 1) == w;
	return !win(N-1, K, ones-1, zeros, !w) || !win(N-1, K, ones, zeros-1, !w);
}
*/

int main() {
	cin.sync_with_stdio(false);
	/*
	rep(ones, 0, 10) {
		rep(zeros, 0, 10) {
			int N = ones + zeros;
			rep(K, 0, N+1) {
				cout << ones << ' ' << zeros << ' ' << K << ": " << win(N, K, ones, zeros) << endl;
			}
		}
	}
	return 0;
	*/
	int N, K;
	cin >> N >> K;
	int ones = 0, zeros = 0;
	rep(i,0,N) {
		int a;
		cin >> a;
		a %= 2;
		if (a) ones++;
		else zeros++;
	}

	cout << (win(N, K, ones, zeros) ? "Stannis" : "Daenerys") << endl;
}