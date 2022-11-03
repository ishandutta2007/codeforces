#include <cstdio>
#include <map>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef vector<int> VI;

int main(){
	int n;
	scanf("%d", &n);
	VI a(n + 1);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	map<int, vector<VI> > lst;
	for (int i = 1; i <= n; ++i)
		if (a[i]){
			VI b;
			for (int t, u = i; a[u];){
				b.push_back(u);
				t = a[u];
				a[u] = 0;
				u = t;
			}
			lst[b.size()].push_back(b);
		}
	VI ans(n + 1);
	for (auto b: lst){
		if (b.st & 1){
			int n = b.st, m = n + 1 >> 1;
			for (int i = 0; i < b.nd.size(); ++i){
				for (int j = 0; j < n; ++j)
					ans[b.nd[i][j]] = b.nd[i][(j + m) % n];
			}
		}
		else if (b.nd.size() & 1){
			ans.clear();
			break;
		}
		else{
			int n = b.st;
			for (int i = 0; i < b.nd.size(); i += 2){
				for (int j = 0; j < n; ++j){
					ans[b.nd[i][j]] = b.nd[i + 1][j];
					ans[b.nd[i + 1][j]] = b.nd[i][(j + 1) % n];
				}
			}
		}
	}
	if (ans.size()){
		for (int i = 1; i <= n; ++i)
			printf("%d%c", ans[i], "\n "[i < n]);
	}
	else
		puts("-1");
	return 0;
}