#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Line {
	int index;
	ll a, b, c;
};

ll gcd(ll a, ll b) {
	return a ? gcd(b%a, a) : b;
}

tuple<ll, ll, ll> intersect(Line& l1, Line& l2) {
	ll det = l1.a * l2.b - l1.b * l2.a;
	if (!det)
		return make_tuple(0, 0, 0);
	ll a = -l2.b * l1.c + l1.b * l2.c;
	ll b = l2.a * l1.c - l1.a * l2.c;
	ll g = gcd(gcd(a, b), det);
	det /= g;
	a /= g;
	b /= g;
	if (det < 0) det *= -1, a *= -1, b *= -1;
	return make_tuple(det, a, b);
}

struct Iset {
	int u, v;
	set<int> st;
	Iset() : u(-1), v(-1) {}
};

bool operator<(const Iset& a, const Iset& b) {
	return sz(a.st) > sz(b.st);
}

vector<Iset> getisets(vector<Line>& lines) {
	int to = sz(lines);
	map<tuple<ll, ll, ll>, Iset> ints;
	rep(i,0,to) {
		rep(j,i+1,to) {
			auto tu = intersect(lines[i], lines[j]);
			if (get<0>(tu) == 0)
				continue; // parallel
			auto& v = ints[tu];
			if (v.u == -1) v.u = lines[i].index, v.v = lines[j].index;
			v.st.insert(i);
			v.st.insert(j);
		}
	}

	vector<Iset> ret;
	trav(pa, ints)
		ret.push_back(pa.second);

	rep(i,0,to) {
		Iset iset;
		iset.v = lines[i].index;
		iset.st.insert(i);
		ret.push_back(iset);
	}

	return ret;
}

vector<pii> output;
void rec(vector<Iset>& isets, int taken, int index, int K, int rem) {
	if (rem == 0)
		throw 0;
	if (index == sz(isets))
		return;
	Iset& is = isets[index];
	if (sz(is.st) * K < rem)
		return;

	// try including it
	int ntaken = taken;
	output.emplace_back(is.u, is.v);
	trav(x, is.st) {
		ntaken |= 1 << x;
	}
	rec(isets, ntaken, index+1, K-1, rem - (int)bitset<32>(ntaken ^ taken).count());
	output.pop_back();

	// try not including it
	rec(isets, taken, index+1, K, rem);
}

int main() {
	int N, K;
	ignore = scanf("%d%d", &N, &K);
	vector<Line> lines;
	rep(i,0,N) {
		int A, B, C;
		ignore = scanf("%d%d%d", &A, &B, &C);
		lines.push_back({i+1, A, B, C});
	}

	while (sz(lines) > K*K) {
		if (K == 0) {
			cout << "NO" << endl;
			return 0;
		}

		vector<Line> smlines(lines.begin(), lines.begin() + K*K+1);
		vector<Iset> isets = getisets(smlines);

		Iset found;
		trav(pa, isets) {
			if (sz(pa.st) <= K)
				continue;
			found = pa;
			break;
		}

		if (found.v == -1) {
			cout << "NO" << endl;
			return 0;
		}

		output.emplace_back(found.u, found.v);

		auto it = found.st.begin();
		int i1 = *it++, i2 = *it++;
		auto ipt = intersect(lines[i1], lines[i2]);

		vector<Line> nlines;
		rep(i,0,sz(lines)) {
			if (i == i1 || intersect(lines[i], lines[i1]) == ipt)
				;
			else
				nlines.push_back(lines[i]);
		}
		nlines.swap(lines);
		--K;
	}

	vector<Iset> isets = getisets(lines);
	sort(all(isets));

	try {
		rec(isets, 0, 0, K, sz(lines));
	} catch(int) {
		cout << "YES" << endl;

		cout << sz(output) << endl;
		trav(pa, output) cout << pa.second << ' ' << pa.first << endl;
		return 0;
	}

	cout << "NO" << endl;
}