#include <cstdio>
#include <queue>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PPI;

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10;

int n, m;
int a[MAXM], b[MAXN];
int ans, cnt;

int main(){
	scanf("%d%d", &n, &m);
	priority_queue<PII> C;
	priority_queue<PPI> P;
	for (int t, i = 1; i <= n; ++i){
		scanf("%d", &t);
		C.push(PII(t, i));
	}
	for (int t, i = 1; i <= m; ++i){
		scanf("%d", &t);
		P.push(PPI(PII(t, 0), i));
	}
	while (!C.empty()){
		for (; !P.empty() && P.top().st.st > C.top().st; ){
			PPI t = P.top();
			t.st.st = t.st.st + 1 >> 1;
			--t.st.nd;
			P.pop();
			P.push(t);
		}
		if (!P.empty() && P.top().st.st == C.top().st){
			PPI t = P.top();
			P.pop();
			++ans, cnt -= t.st.nd;
			a[t.nd] = -t.st.nd;
			b[C.top().nd] = t.nd;
		}
		C.pop();
	}
	printf("%d %d\n", ans, cnt);
	for (int i = 1; i <= m; ++i)
		printf("%d%c", a[i], "\n "[i < m]);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", b[i], "\n "[i < n]);
	return 0;
}