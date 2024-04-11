#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<memory.h>
#include<set>
#include<map>
#include<queue>
#include<cstring>
#include<sstream>
#define SS stringstream
#define pw(x) (1ll << (x))
#define m0(x) memset(x, 0, sizeof(x))
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int a[111], b[111];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	for (int s = 1; s <= n; s++) {
		int bad = 0;
		for (int i = 0; i < s; i++) b[i] = a[i];
		for (int i = s; i < n; i++) {
			int mm  = 0, l;
			for (int j = 0;  j< s; j++) {
				if (b[j] > mm) {
					 mm = b[j];
					 l = j;
				}
			}
			if (mm == 0) {
				bad = 1;
				break;
			}
			b[l] = min(b[l] - 1, a[i]);
		}		
		if (!bad) {
			cout << s << endl;
			break;
		}
	}
	return 0;
}