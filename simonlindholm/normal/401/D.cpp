#include <iostream>
#include <bitset>
#include <sstream>
#include <vector>
using namespace std;

int M;
string str;
int sz;

vector<vector<long long> > mem;
long long solve(int mask, int mod, int digitVal) {
	if (!mask) {
		return mod == 0 ? 1 : 0;
	}

	long long& out = mem[mod][mask];
	if (out != -1)
		return out;
	long long r = 0;
	bitset<10> used;
	if ((mask & (mask - 1)) == 0)
		used.set(0);
	for (int i = 0; i < sz; ++i) {
		if (mask & (1 << i)) {
			int mask2 = mask ^ (1 << i);
			int v = (str[i] - '0');
			if (used.test(v))
				continue;
			used.set(v);
			int mod2 = (mod + digitVal * v) % M;
			r += solve(mask2, mod2, digitVal * 10 % M);
		}
	}
	return out = r;
}

int main() {
	long long N;
	cin >> N >> M;
	stringstream ss;
	ss << N;
	::str = ss.str();
	::sz = str.size();
	mem.assign(M, vector<long long>(1 << sz, -1));
	cout << solve((1 << sz) - 1, 0, 1 % M) << endl;
	return 0;
}