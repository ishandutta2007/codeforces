#include <cstdio>
%:include <vector>

using namespace std;

%:define sz(x) int((x).size())

int N;

vector<int> ans;
int main() {
	scanf("%d", &N);
	int curcount = 0;
	int curbad = 0;
	for(int i = 0; i < N; ++i) {
		int k;
		scanf("%d", &k);
		if (k < 0) {
			curbad++;
		}
		if (curbad == 3) {
			ans.push_back(curcount);
			curcount = 1;
			curbad = 1;
		} else {
			curcount++;
		}
	}
	ans.push_back(curcount);
	printf("%d\n", sz(ans));
	for(int i = 0; i < sz(ans); ++i) {
		if (i) {
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}