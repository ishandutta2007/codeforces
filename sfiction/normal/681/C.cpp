#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

int main(){
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int> > Q;
	vector<PII> ans;
	char com[10];
	for (int x, i = 0; i < n; ++i){
		scanf("%s%d", com, &x);
		switch (com[0]){
		case 'i':
			Q.push(x);
			ans.push_back(PII(0, x));
			break;
		case 'g':
			while (!Q.empty() && Q.top() < x){
				Q.pop();
				ans.push_back(PII(2, 0));
			}
			if (Q.empty() || Q.top() > x){
				Q.push(x);
				ans.push_back(PII(0, x));
			}
			ans.push_back(PII(1, x));
			break;
		case 'r':
			if (Q.empty()){
				Q.push(0);
				ans.push_back(PII(0, 0));
			}
			Q.pop();
			ans.push_back(PII(2, 0));
			break;
		}
	}
	printf("%d\n", (int)ans.size());
	char *op[3] = {"insert", "getMin", "removeMin"};
	for (int i = 0; i < ans.size(); ++i)
		if (ans[i].st < 2)
			printf("%s %d\n", op[ans[i].st], ans[i].nd);
		else
			puts(op[2]);
	return 0;
}