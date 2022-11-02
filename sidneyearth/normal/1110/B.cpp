#include <stdio.h>
#include <queue>
using namespace std;
int b[100100];
priority_queue<int> q;
int main(){
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	int ans = n;
	for(int i = 2; i <= n; i++)
		q.push(-(b[i] - b[i-1] - 1));
	for(int i = 1; i <= n - k; i++){
		ans += -q.top();
		q.pop();
	}
	printf("%d\n", ans);
	return 0;
}