#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int tp[maxn];
int cnt[maxn];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int cur;
			scanf("%d", &cur);
			if (cur) tp[i] ^= (1 << j);
		}
		cnt[tp[i]]++;
	}
	if (cnt[0]) cout << "YES" << endl;
	else {
		for (int j = 1; j < (1 << k); j++) {
			for (int s = 1; s < (1 << k); s++)
				if ((cnt[j] && cnt[s]) && ((j & s) == 0)) {
					cout << "YES" << endl;
					return 0;
				}
		}
		cout << "NO" << endl;
	}
	return 0;
}
/*
1 2
..
*/