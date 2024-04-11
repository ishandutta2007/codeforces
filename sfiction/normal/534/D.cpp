#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2E5 + 10;

vector<int> a[MAXN];

int main(){
	int n;
	scanf("%d", &n);
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		a[t].push_back(i);
	}

	int b[3] = {0, 0, 0};
	vector<int> ans;
	int u = -1;
	for (int i = 0; i < n; ++i){
		++u;
		for (; u >= 0 && a[u].size() == 0; u -= 3);
		if (u < 0)
			break;
		ans.push_back(a[u].back());
		a[u].pop_back();
	}

	if (ans.size() < n)
		puts("Impossible");
	else{
		puts("Possible");
		for (int i = 0; i < n; ++i)
			printf("%d%c", ans[i], "\n "[i + 1 < n]);
	}
	return 0;
}