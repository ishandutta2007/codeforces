#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = (ll) 1e10 + 7;

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a[3];
	cin >> a[0] >> a[1] >> a[2];

	cout << "First" << endl;
	cout << INF << endl;

	int t;
	cin >> t;
	a[t - 1] += INF;

	vector <ll> d = {a[0], a[1], a[2]};
	sort(d.begin(), d.end());
	ll x = d[1] - d[0], y = d[2] - d[1];

	cout << x + 2 * y << endl;

	cin >> t;
	a[t - 1] += x + 2 * y;

	d = {a[0], a[1], a[2]};
	sort(d.begin(), d.end());
	x = d[1] - d[0];

	cout << x << endl;

}