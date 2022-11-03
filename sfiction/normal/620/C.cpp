#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

int main(){
	int n;
	scanf("%d", &n);
	map<int, int> lst;
	vector<PII> ans;
	int r = 0;
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		if (++lst[t] == 2){
			lst.clear();
			ans.push_back(PII(r + 1, i));
			r = i;
		}
	}
	if (ans.size()){
		ans.back().nd = n;
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); ++i)
			printf("%d %d\n", ans[i].st, ans[i].nd);
	}
	else
		puts("-1");
	return 0;
}