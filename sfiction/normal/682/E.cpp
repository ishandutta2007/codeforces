#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;

ll cross(const PLL &a, const PLL &b, const PLL &c, const PLL &d){
	return (b.st - a.st) * (d.nd - c.nd) - (b.nd - a.nd) * (d.st - c.st);
}

void convex_hull(vector<PLL> &a){
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	if (a.size() < 3)
		return;
	
	vector<PLL> b;
	for (int m = 1, o = 1, i = 0; i >= 0; i += o){
		for (; b.size() > m && cross(b[b.size() - 2], b.back(), b.back(), a[i]) >= 0; b.pop_back());
		b.push_back(a[i]);
		if (i + 1 == a.size())
			m = b.size(), o = -1;
	}
	b.pop_back();
	a.swap(b);
}

int main(){
	int n;
	scanf("%d%*I64d", &n);
	vector<PLL> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%I64d%I64d", &a[i].st, &a[i].nd);
	convex_hull(a);
	n = a.size();
	a.push_back(a.front());

	ll ans = 0;
	vector<PLL> s(3);
	for (int k = 1; k < n - 1; ++k){
		int l = 0, r = k, m = k + 1;
		for (; l < n; ++l, r = (r + 1) % n){
			for (; cross(a[l], a[r], a[m], a[m + 1]) < 0; m = (m + 1) % n);

			ll res = cross(a[l], a[m], a[l], a[r]);
			if (ans < res){
				ans = res;
				s[0] = a[l], s[1] = a[r], s[2] = a[m];
			}
		}
	}
	s.push_back(s[0]);
	s.push_back(s[1]);
	for (int i = 0; i < 3; ++i)
		printf("%I64d %I64d\n", s[i + 1].st + s[i + 2].st - s[i].st, s[i + 1].nd + s[i + 2].nd - s[i].nd);
	return 0;
}