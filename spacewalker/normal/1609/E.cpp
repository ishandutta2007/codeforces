#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 100010;

struct ABCTrack {
	int a, b, c, ab, bc, abc;
	ABCTrack() : a(0), b(0), c(0), ab(0), bc(0), abc(0) {}
	ABCTrack operator + (ABCTrack o) {
		ABCTrack acopy = *this, ocopy = o;
		auto formWith = [&] (int &x, int &y, int &xy) {
			int opts = min(x, y);
			x -= opts; y -= opts; xy += opts;
		};
		ABCTrack ans;
		ans.abc = acopy.abc + ocopy.abc;
		formWith(acopy.a, ocopy.bc, ans.abc);
		formWith(acopy.ab, ocopy.c, ans.abc);
		if (acopy.ab > 0 && ocopy.bc > 0) {
			int opts = min(acopy.ab, ocopy.bc);
			acopy.b += opts;
			acopy.ab -= opts; ocopy.bc -= opts;
			ans.abc += opts;	
		}
		ans.ab = acopy.ab + ocopy.ab;
		formWith(acopy.a, ocopy.b, ans.ab);
		ans.bc = acopy.bc + ocopy.bc;
		formWith(acopy.b, ocopy.c, ans.bc);
		ans.a = acopy.a + ocopy.a;
		ans.b = acopy.b + ocopy.b;
		ans.c = acopy.c + ocopy.c;
		return ans;
	}
};

struct ABCTree {
	int al, ar;
	ABCTrack track;
	ABCTree *left, *right;
	void debug() {
		printf("ABCT(%d, %d) %d %d %d %d %d %d\n", al, ar, track.a, track.b, track.c, track.ab, track.bc, track.abc);
		if (left != nullptr) {
			left->debug();
			right->debug();
		}
	}
	~ABCTree() {
		if (left != nullptr) {
			delete left;
			delete right;
		}
	}
	ABCTree(int i, int j) : al(i), ar(j), track(), left(nullptr), right(nullptr) {
		if (i != j) {
			int k = (i + j) / 2;
			left = new ABCTree(i, k);
			right = new ABCTree(k + 1, j);
		}
	}
	void setTrackTo(int i, ABCTrack trk) {
		if (i < al || ar < i) return;
		else if (al == ar) track = trk;
		else {
			left->setTrackTo(i, trk);
			right->setTrackTo(i, trk);
			track = left->track + right->track;
		}
	}
};


char s[NMAX];
int main() {
	int n, q; scanf("%d %d", &n, &q);
	scanf("%s", s);
	ABCTree ij(0, n-1);
	auto trackForChar = [&] (char c) {
		ABCTrack ans;
		if (c == 'a') ans.a = 1;
		else if (c == 'b') ans.b = 1;
		else if (c == 'c') ans.c = 1;
		return ans;
	};
	for (int i = 0; i < n; ++i) ij.setTrackTo(i, trackForChar(s[i]));
	while (q--) {
		int pos; char c; scanf("%d %c", &pos, &c); --pos;
		s[pos] = c;
		ij.setTrackTo(pos, trackForChar(c));
		// ij.debug();
		printf("%d\n", ij.track.abc);
		continue;
		int cans = ij.track.abc;
		int a = 0, ab = 0, abc = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'a') ++a;
			if (s[i] == 'b' && a > 0) ab++, a--;
			if (s[i] == 'c' && ab > 0) abc++, ab--;
		}
		// printf("%s ^ expected %d\n", s, abc);
		assert(cans == abc);
	}
}