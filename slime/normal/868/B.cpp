#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
double h, m, s, t[2];
bool check(int l, int r) {
	if (h >= l && h <= r) return 0;
	if (m >= l && m <= r) return 0;
	if (s >= l && s <= r) return 0;
	return 1;
}
int main() {
	cin >> h >> m >> s >> t[0] >> t[1];
	h *= 5, t[0] *= 5, t[1] *= 5;
	if (h > 59.9) h = 0;
	if (t[0] > 59.9) t[0] = 0;
	if (t[1] > 59.9) t[1] = 0;
	if (m || s) h += 1;
	if (s) m += 0.5;
	if (t[0] > t[1]) swap(t[0], t[1]);
	if (check(t[0], t[1])) printf("YES\n");
	else if (check(0, t[0]) && check(t[1], 60)) printf("YES\n");
	else printf("NO\n"); 
	return 0;
}