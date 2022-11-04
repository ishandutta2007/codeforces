// #include <iostream>
// #include <vector>
// #include <iomanip>

// using namespace std;

// #define ld long double
// #define ll long long
// #define pii pair<int, int>

// int n, p;
// vector<int> arr;


// bool checker(ld time)
// {
//     ld sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ld need = time * a[i] - b[i];
//         if (need < 1e-9)
//             continue;
//         sum += need;
//     }
//     return sum <= time * p;
// }

 
// int main()
// {
// 	cin >> n >> p;
//     ll sum = 0;
//     for (int i = 0; i < n; i++) {
//         a[i] = readInt(), b[i] = readInt();
//         sum += a[i];
//     }
//     if (sum <= p) {
//         writeInt(-1, '\n');
//         return 0;
//     }
//     long double l = 0.0;
//     long double r = 1e18;
//     for (int i = 0; i < 100; i++) {
//         long double mid = (l + r) / 2.0;
//         if (get(mid)) {
//             l = mid;
//         } else {
//             r = mid;
//         }
//     }
//     printf("%.9lf\n", (double)l);
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ld = long double;

bool check(vector<pii> &arr, ld time, int p)
{
	ld charger_time = time;
	for (auto x : arr)
		if (x.first * time > x.second)
			charger_time -= (x.first * time - x.second) / p;
	return charger_time >= 0;
}

int main()
{
	int n, p;
	cin >> n >> p;
	vector<pii> arr(n);
	ll sm = 0;
	for (auto &x : arr)
	{
		cin >> x.first >> x.second;
		sm += x.first;
	}
	if (sm <= p)
	{
		cout << -1 << endl;
		return 0;
	}
	ld l = 0, r = 1e10;
	for (int i = 0; i < 100; ++i)
	{
		ld c = (r + l) / 2;
		if (check(arr, c, p))
			l = c;
		else
			r = c;
	}
	cout << fixed << setprecision(10) << l << endl;
}