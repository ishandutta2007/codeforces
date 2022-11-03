#include <cstdio>
#include <vector>

using namespace std;

int val[1024];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		val[i] = 1e9 + 1;
	vector<int> lst;
	for (int i = 9; i >= 0; --i)
		for (int k = 0; k < 2; ++k){
			lst.clear();
			for (int j = 0; j < n; ++j)
				if ((j >> i & 1) == k)
					lst.push_back(j + 1);
			if (!lst.size())
				continue;

			printf("%d\n", (int)lst.size());
			for (int j = 0; j < lst.size(); ++j)
				printf("%d%c", lst[j], "\n "[j + 1 < lst.size()]);
			fflush(stdout);

			for (int t, j = 0; j < n; ++j){
				scanf("%d", &t);
				if ((j >> i & 1) == !k)
					val[j] = min(val[j], t);
			}
		}
	puts("-1");
	for (int i = 0; i < n; ++i)
		printf("%d%c", val[i], "\n "[i + 1 < n]);
	return 0;
}