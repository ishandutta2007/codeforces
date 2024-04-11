#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pli;

#define N 300100

int n, h[N], b[N];
ll dp[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    dp[0] = 0;
    stack <pli> st;
    multiset <ll> S;
    for (int i = 1; i <= n; i ++) {
		ll val = dp[i-1];
		while (!st.empty() && h[st.top().second] > h[i]) {
			val = max(val, st.top().first);
			S.erase(S.find(st.top().first + b[st.top().second]));
			st.pop();
		}
		S.insert(val + b[i]);
		st.emplace(val, i);
		dp[i] = *S.rbegin();
    }
    printf("%lld\n", dp[n]);

    return 0;
}