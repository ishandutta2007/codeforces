#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 200000

using namespace std;

class staticrsq {
	vector<int> partials;
public:
	staticrsq(vector<int> orig) : partials(orig.size() + 1, 0) {
		for (int i = 0; i < orig.size(); ++i) {
			partials[i+1] = partials[i] + orig[i];
		}
	}
	int query (int i, int j) {
		return partials[j + 1] - partials[i];
	}
};

int main() {

	int n, k, q; scanf("%d %d %d", &n, &k, &q);

	vector<int> admctdiff(MAX, 0);
	for (int i = 0; i < n; ++i) {
		int l, r; scanf("%d %d", &l, &r);
		++admctdiff[l-1];
		if (r < MAX) {
			--admctdiff[r];
		}
	}

	staticrsq karen(admctdiff);
	vector<int> isAd(MAX, 0);
	for (int i = 0; i < MAX; ++i) {
		if (karen.query(0, i) >= k) {
			isAd[i] = 1;
		}
	}

	staticrsq covfefe(isAd);
	for (int i = 0; i < q; ++i) {
		int li, ri; scanf("%d %d", &li, &ri);
		printf("%d\n", covfefe.query(li - 1, ri - 1));
	}

	return 0;
}