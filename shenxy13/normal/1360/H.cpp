#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d %d", &n, &m);
		long long med = (1LL << (m - 1)) - 1,x1 = med, x2 = med + 1;
		char num[m];
		set<long long> bannum;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) scanf(" %c", &num[j]);
			long long lnum = 0;
			for (int j = 0; j < m; ++j) {
				if (num[j] == '1') lnum += 1LL << (m - 1 - j);
			}
			bannum.insert(lnum);
			bool dec = false;
			while (bannum.find(med) != bannum.end()) --med, dec = true;
			if (dec) --x1;
			else if (lnum < med) --x1;
			else --x2;
			if (x1 + 1 < x2) {
				++med;
				while (bannum.find(med) != bannum.end()) ++med;
				++x1, --x2;
			} else if (x2 < x1) {
				--med;
				while (bannum.find(med) != bannum.end()) --med;
				--x1, ++x2;
			}
		}
		for (int i = 0; i < m; ++i) num[m - 1 - i] = (med & (1LL << i)) ? '1' : '0';
		for (int i = 0; i < m; ++i) printf("%c", num[i]);
		printf("\n");
	}
	return 0;
}