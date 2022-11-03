#include <cstdio>
#include <set>

using namespace std;

set<int> lst;

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		if (t == i)
			++ans;
		else
			lst.insert(t);
	}
	printf("%d\n", ans += lst.size() >> 1);
	return 0;
}