#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)

typedef pair<int, int> pii;

const int MAXN = 1010;

vector<int> ar[MAXN];
int rows[MAXN];

int N;
pii cnts[MAXN];

int arr[MAXN];
int loc[MAXN];

vector<pii> colswap;
vector<pii> rowswap;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		rows[i] = i;
	}
	for(int i = 1; i < N; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		ar[a].push_back(b);
	}

	for(int i = 1; i <= N; ++i) {
		arr[i] = loc[i] = i;
	}

	int cur = 1;
	for(int i = 1; i <= N; ++i) {
		int width = 0;
		repi(j, ar[i]) {
			int p = loc[*j];
			if (p >= cur) {
				arr[p] = arr[cur];
				loc[arr[cur]] = p;
				if (p != cur)
					colswap.push_back(pii(p, cur));
				if (cur > width) width = cur;
				++cur;
			} else if (p > width) width = p;
		}
		cnts[i] = pii(width, i);
	}

	for(int i = 1; i <= N; ++i) {
		arr[i] = loc[i] = i;
	}

	sort(cnts + 1, cnts + 1 + N);
	for(int i = 1; i <= N; ++i) {
		int guy = cnts[i].second;
		int l = loc[guy];
		if (l == i) continue;
		int curr = arr[i];
		loc[curr] = l;
		arr[l] = curr;
		rowswap.push_back(pii(i, l));
	}

	int size = rowswap.size() + colswap.size();
	printf("%d\n", size);
	repi(i, rowswap) {
		printf("1 %d %d\n", i->first, i->second);
	}
	repi(i, colswap) {
		printf("2 %d %d\n", i->first, i->second);
	}

	return 0;
}