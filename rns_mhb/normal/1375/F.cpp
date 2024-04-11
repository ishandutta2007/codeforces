#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

pii a[3];

int query(ll y) {
	printf("%I64d\n", y);
	fflush(stdout);
	int x;
	cin >> x;
	for(int i = 0; i < 3; i ++) if(a[i].second == x) {
		a[i].first += y;
	}
	sort(a, a+3);
	return x;
}

int main() {
	cin >> a[0].first >> a[1].first >> a[2].first;
	a[0].second = 1, a[1].second = 2, a[2].second = 3;

    puts("First");
    if(query(1ll<<35) == 0) return 0;
    if(query(2*a[2].first - a[1].first - a[0].first) == 0) return 0;
    if(query(a[1].first-a[0].first) == 0) return 0;
}