#include <cstdio>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;

int n, B;
ll ans[MAXN];
ll a[MAXN], s[MAXN];

int main(){
	scanf("%d%d", &n, &B);
	++B;
	queue<ll> Q;
	ll last = 0;
	for (int i = 0; i < n; ++i){
		ans[i] = -1;
		scanf("%I64d%I64d", &a[i], &s[i]);
		for (; !Q.empty() && (last = max(last, a[Q.front()])) + s[Q.front()] <= a[i]; Q.pop())
			ans[Q.front()] = last += s[Q.front()];
		if (Q.size() < B)
			Q.push(i);
	}
	for (; !Q.empty(); Q.pop()){
		last = max(last, a[Q.front()]);
		ans[Q.front()] = last += s[Q.front()];
	}
	for (int i = 0; i < n; ++i)
		printf("%I64d%c", ans[i], "\n "[i < n - 1]);
	return 0;
}