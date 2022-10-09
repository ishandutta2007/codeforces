#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <cassert>
 
using namespace std;
 
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;
const int K = 330;

int a[100100];
int l[500], r[500];
ll sum[100100];
multiset<ll> mx;

int main() {
	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum[i + 1] = sum[i] + a[i];
	}
	for (int i = 0; i < K + 1; ++i) {
		l[i] = -1;
		r[i] = n;
	}
	mx.insert(sum[0] - sum[n]);
	for (int q = 0; q < n; ++q) {
		int p;
		cin >> p;
		--p;
		int ind = p / K, L = l[ind], R = r[ind];
		for (int i = p - 1; i >= ind * K; --i) { 
			if (a[i] == -1) {
				L = i;
				break;
			}
		}
		for (int i = p + 1; i < (ind + 1) * K; ++i) {
			if (a[i] == -1 || i == n) {
				R = i;
				break;
			}
		}
		//cout << L << " " << R << endl;
		if (mx.find(sum[L + 1] - sum[R]) == mx.end()) {
			cout << "!";
			return 1;
		}
		mx.erase(mx.find(sum[L + 1] - sum[R]));
		mx.insert(sum[L + 1] - sum[p]);
		mx.insert(sum[p + 1] - sum[R]);
		cout << -(*mx.begin()) << endl;
		a[p] = -1;
		for (int i = 0; i < ind; ++i) {
			r[i] = min(r[i], p);
		}
		for (int i = ind + 1; i < K; ++i) {
			l[i] = max(l[i], p);
		}
		/*for (int i = 0; i < K; ++i) {
			cout << l[i] << " " << r[i] << " ";
		}
		cout << endl;*/
	}
    return 0;
}