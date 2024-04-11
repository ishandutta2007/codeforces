#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

const int maxN = 310;

int a[maxN];
int b[maxN][maxN];
int n;

int res[maxN];
int score[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &b[i][j]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; ++i)
		score[i] = n + 1;

	int best = n + 1, card = 0;
	set < pair < int, int > > S; 
	for (int i = 1; i <= n; ++i) {
		int current = 0;
		for (int j = 1; j <= n; ++j)
			if (a[j] == i) {
				current = j;
				break;
			}
		S.insert(make_pair(current, i));
		card = S.begin()->second;
		for (int j = 1; j <= n; ++j)
			if (card != j) {
				int index = 0;
				for (int k = 1; k <= n; ++k)
					if (card == b[j][k]) {
						index = k;
						break;
					}
				if (index < score[j]) {
					score[j] = index;
					res[j] = card;
				}
			} else {
				if (S.size() >= 2) {
					set < pair < int, int > > :: iterator it = S.begin();
					++it;
					int ncard = it->second;
					int index = 0;
					for (int k = 1; k <= n; ++k)
						if (ncard == b[j][k]) {
							index = k;
							break;
						}
					if (index < score[j]) {
						score[j] = index;
						res[j] = ncard;
					}
				}
			}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
	printf("\n");
	return 0;
}