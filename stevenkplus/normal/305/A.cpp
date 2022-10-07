#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 110;
int ar[MAXN];
int N;

bool cont[MAXN];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar +i );
		cont[ar[i]] = true;
	}

	vector<int> ans;
	bool ones = true;
	bool tens = true;


	if (cont[0]) {
		ans.push_back(0);
	}
	for(int i = 1; i < 10; ++i) {
		if (cont[i]) {
			ones = false;
			ans.push_back(i);
			break;
		}
	}

	for(int i = 10; i <= 90; i += 10) {
		if (cont[i]) {
			tens = false;
			ans.push_back(i);
			break;
		}
	}

	if (ones && tens) {
		for(int i = 1; i < 100; ++i) {
			if (cont[i]) {
				ans.push_back(i);
				break;
			}
		}
	}

	if (cont[100]) ans.push_back(100);

	printf("%d\n", int(ans.size()));
	for(int i = 0; i < int(ans.size()); ++i) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}