#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);
const int size = 300 * 1000 + 100;
const long long mdl = 1000 * 1000 * 1000 + 7;
long long base1 = 17239;
long long base2 = 23917;
const int alpha = 26;

char s[size], t[size];
int n, m;

long long ht1[alpha];
long long ht2[alpha];
long long pwr1[size], pwr2[size];
bool ans[size];
long long st1[size][alpha];
long long st2[size][alpha];
int way[alpha];
bool used[size];

int main() {
	pwr1[0] = 1;
	pwr2[0] = 1;
	for (int i = 1; i < size; i++) {
		pwr1[i] = (pwr1[i - 1] * base1) % mdl;
		pwr2[i] = pwr2[i - 1] * base2;
	}

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%s%s", s, t);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < alpha; j++) {
			ht1[j] = (ht1[j] * base1) % mdl;
			ht2[j] = (ht2[j] * base2);
		}	

		ht1[t[i] - 'a']++;
		ht1[t[i] - 'a'] %= mdl;

		ht2[t[i] - 'a']++;
	}

	vector <pair <pair <long long, long long>, int> > fst, scd;
	for (int i = 0; i < alpha; i++)
		scd.pb(mp(mp(ht1[i], ht2[i]), i));
	sort(scd.begin(), scd.end());
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < alpha; j++) {
			st1[i + 1][j] = (st1[i][j] * base1) % mdl;
			st2[i + 1][j] = st2[i][j] * base2;
		}

		st1[i + 1][s[i] - 'a']++;
		st1[i + 1][s[i] - 'a'] %= mdl;

		st2[i + 1][s[i] - 'a']++;

		if (i >= m - 1) {
			fst.clear();
			for (int j = 0; j < alpha; j++) {
				fst.pb(mp(mp((st1[i + 1][j] - (st1[i - m + 1][j] * pwr1[m]) % mdl + mdl) % mdl, st2[i + 1][j] - st2[i - m + 1][j] * pwr2[m]), j));
			} 

			sort(fst.begin(), fst.end());
			ans[i] = true;
			for (int j = 0; j < alpha; j++) {
				way[fst[j].sc] = scd[j].sc;
				used[fst[j].sc] = (fst[j].fs != mp(0ll, 0ll));
				ans[i] = ans[i] && (fst[j].fs == scd[j].fs);
			}

			for (int j = 0; j < alpha; j++) {
				if (used[j] && used[way[j]] && way[way[j]] != j) {
					ans[i] = false;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += ans[i];
   	printf("%d\n", cnt);
   	for (int i = 0; i < n; i++)
   		if (ans[i])
   			printf("%d ", i - m + 2);


    return 0;
}