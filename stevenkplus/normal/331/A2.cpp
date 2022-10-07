#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 300100;

map<int, int> mymap;


int N;
int ar[MAXN];
int ans[MAXN];
ll prfs[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		scanf("%d", ar + i);
		mymap[ar[i]] = i;
		int add = ar[i];
		if (add < 0) add = 0;
		prfs[i + 1] = prfs[i] + add;
	}

	ll bst = 0;
	int trace = -1;
	for(int i = 1; i <= N; ++i) {
		int oth = mymap[ar[i]];
		if (oth > i) {
			ll val = prfs[oth] - prfs[i + 1];
			val += 2 * ar[i];
			if (val > bst || trace == -1) {
				bst = val;
				trace = i;
			}
		}
	}

//	printf("trace = %d\n", trace);
	int pos = 0;
	for(int i = 1; i < trace; ++i) {
		ans[pos] = i;
		++pos;
	}
	int oth = mymap[ar[trace]];
	for(int i = trace + 1; i < oth; ++i) {
		if (ar[i] < 0) {
			ans[pos] = i;
			++pos;
		}
	}
	for(int i = oth + 1; i <= N; ++i) {
		ans[pos] = i;
		++pos;
	}

	cout << bst << " " << pos << "\n";
	for(int i = 0; i < pos; ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << "\n";

	return 0;
}