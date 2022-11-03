#include <cstdio>
#include <map>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	map<int, int> lst;
	int ans = -1;
	for (int t, i = 0; i < n; ++i){
		scanf("%d", &t);
		if (lst.count(t))
			++lst[t];
		else
			lst[t] = 1;
		if (ans == -1 || lst[t] > lst[ans])
			ans = t;
	}
	printf("%d\n", ans);
	return 0;
}