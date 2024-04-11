#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 2E5 + 10;

int n, A, B, K;
char s[MAXN];

int main(){
	scanf("%d%d%d%d", &n, &A, &B, &K);
	scanf("%s", s + 1);
	int pre = 0;
	priority_queue<PII> Q;
	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if (s[i] == '1'){
			if (i - pre - 1 >= B){
				Q.push(PII(i - pre - 1, pre));
				tot += (i - pre - 1) / B;
			}
			pre = i;
		}
	if (n - pre >= B){
		Q.push(PII(n - pre, pre));
		tot += (n - pre) / B;
	}

	vector<int> ans;
	do{
		PII t = Q.top();
		Q.pop();
		--tot;
		if (t.st - B >= B)
			Q.push(PII(t.st - B, t.nd + B));

		ans.push_back(t.nd + B);
	}while (tot >= A);

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);

	return 0;
}