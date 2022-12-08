#include <bits/stdc++.h>

using namespace std;
#define ll long long

int la, ra, ta;
int lb, rb, tb;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	int gc = __gcd(ta, tb);

	if (lb < la) {
		swap(lb, la);
		swap(ra, rb);
		swap(ta, tb);
	}

	int lena = ra-la+1;
	int lenb = rb-lb+1;

	int delt = lb-la;

	int tmp = delt/gc;

	int diff = delt - tmp*gc;
	int cur = lena - diff;

	int ans = 0;
	ans = max(ans, min(cur, lenb));

	diff -= gc;
	diff = 0-diff;
	cur = lenb - diff;

	ans = max(ans, min(lena, cur));

	cout << ans << endl;


}