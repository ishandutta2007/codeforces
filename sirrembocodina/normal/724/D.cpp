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

char S[100100];
int s[100100];
int dp[100100];
int cnt[50];

int main() {
	int n, m;
	cin >> m >> S;
	n = strlen(S);
	forn (i, n) {
		s[i] = S[i] - 'a';
		cnt[s[i]]++;
	}
	s[n] = -1;
	forn (a, 26) {
		int j = -1, l = -1;
		forn (i, n + 1) {
			if (s[i] > a) {
			} else if (j < i - m && l < i - m) {
				dp[i] = 1000000000;
			} else if (l >= i - m && l == -1) {
				dp[i] = s[i] == a;
			} else if (l >= i - m) {
				dp[i] = dp[l] + (s[i] == a);
			} else if (j == -1) {
				dp[i] = s[i] == a;
			} else {
				dp[i] = dp[j] + (s[i] == a);
			}
			/*cout << i << " " << j << " " << l << " ";
			if (s[i] <= a) {
				cout << dp[i];
			}
			cout << endl;*/
			if (s[i] < a) {
				l = i;
			}
			if (j < i - m) {
				if (s[i] == a) {
					j = i;
				}
			} else if (j == i - m) {
				for (int k = i - m + 1; k <= i; ++k) {
					if (s[k] == a) {
						j = k;
						break;
					}
				}
			}
		}
//		cout << endl;
		if (dp[n] >= 1000000000) {
			forn (i, cnt[a]) {
				cout << char('a' + a);
			}
			continue;
		}
		forn (i, dp[n]) {
			cout << char('a' + a);
		}
		break;
	}
    return 0;
}