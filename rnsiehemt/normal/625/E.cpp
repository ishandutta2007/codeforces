#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 100005;

int N, next[MaxN], prev[MaxN];
ll M, p[MaxN], t[MaxN], s[MaxN];
bool alive[MaxN];
std::priority_queue<std::pair<ll, int>> q;

ll ceil(ll n, ll d) {
	return (n + d-1) / d;
}
bool go(int a, int b) {
	if (a > b && t[a] < t[b]) {
		ll p1 = p[a], p2 = p[b];
		p1 = (p1 + (t[b]-1-t[a]) * s[a]) % M;
		if (p2 < p1) p2 += M;
		if (p1 + s[a] >= p2) return true;
	}

	ll p1 = p[a], p2 = p[b];
	if (t[a] < t[b]) p1 = (p1 + (t[b]-t[a]) * s[a]) % M;
	else p2 = (p2 + (t[a] - t[b]) * s[b]) % M;

	if (p2 < p1) p2 += M;
	return s[a] > s[b] || (a < b && p1 + s[a] >= p2);
}

std::pair<ll, int> time2(int a, int b) {
	assert(go(a, b));
	//assert(s[a] > s[b]);
	if (a > b && t[a] < t[b]) {
		ll p1 = p[a], p2 = p[b];
		p1 = (p1 + (t[b]-1-t[a]) * s[a]) % M;
		if (p2 < p1) p2 += M;
		if (p1 + s[a] >= p2) return {t[b], a};
	}
	ll p1 = p[a], p2 = p[b];

	ll time = std::max(t[a], t[b]);
	if (t[a] < t[b]) p1 = (p1 + (t[b]-t[a]) * s[a]) % M;
	else p2 = (p2 + (t[a] - t[b]) * s[b]) % M;

	if (p2 < p1) p2 += M;
	if (b < a) p2 += s[b];

	if (p2 <= p1 + s[a]) return {time + 1ll, a};
	else return {time + 1 + ceil(p2 - (p1 + s[a]), s[a] - s[b]), a};
}
std::pair<ll, int> time(int a, int b) {
	auto foo = time2(a, b);
	foo.first *= -1; foo.second *= -1;
	return foo;
}

int main()
{
	scanf("%d%lld", &N, &M);
	std::vector<std::pair<ll, int>> v;
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &p[i], &s[i]);
		p[i] %= M;
		v.push_back({p[i], i});
		t[i] = 0;
		alive[i] = true;
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		int a = v[i].second, b = v[(i+1)%N].second;
		next[a] = b;
		prev[b] = a;
	}
	for (int i = 0; i < N; i++) if (go(i, next[i])) q.push(time(i, next[i]));
	while (!q.empty()) {
		auto foo = q.top(); q.pop();
		int i = -foo.second; ll curtime = foo.first;
		if (!alive[i]) continue;
		if (!go(i, next[i]) || time(i, next[i]) != foo) continue;
		int count = 0;
		while (next[i] != i && go(i, next[i])) {
			assert(alive[next[i]]);
			if (go(i, next[i]) && time(i, next[i]).first == curtime) {
				alive[next[i]] = false;
				//printf("rip %d\n", next[i]+1);
				count++;
				next[i] = next[next[i]];
				prev[next[i]] = i;
			} else break;
			assert(alive[next[i]]);
		}
		assert(count >= 1);
		curtime = -curtime;
		p[i] = (p[i] + (curtime - t[i]) * s[i]) % M;
		t[i] = curtime;
		s[i] -= count;
		if (s[i] < 0) s[i] = 0;
		if (go(prev[i], i)) q.push(time(prev[i], i));
		if (go(i, next[i])) q.push(time(i, next[i]));
	}
	int ans = 0;
	for (int i = 0; i < N; i++) if (alive[i]) ans++;
	printf("%d\n", ans);
	for (int i = 0; i < N; i++) if (alive[i]) printf("%d ", i+1);
	printf("\n");
}