#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 100;

int n, m;
int a[MAXN];

int main(){
	int cnt = 0;
	scanf("%d%d", &n, &m);
	for (int i=0;i<m;++i){
		int k;
		scanf("%d", &k);
		for (int j=0;j<k;++j)
			scanf("%d", &a[j]);

		if (a[0] == 1){
			int j;
			for (j=1;j<k && a[j] == j + 1; ++j);
			cnt = j;
		}
	}
	printf("%d\n", n - m - (cnt - 1) + n - cnt);

	return 0;
}