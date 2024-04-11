#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

string ItemNames[] = {"weapon", "armor", "orb"};
string ResNames[] = {"gladiator", "sentry", "physician"};

int GetIndex(const string &s, string *pArr) {
	for (int i = 0; i<3; i++) if (pArr[i] == s) return i;
	assert(0);
	return -1;
}

struct Item {
	string name;
	int type;
	int params[3];
	int size;
};

struct Res {
	string name;
	int type;
	int home;
	int bonus;
	inline bool operator< (const Res &other) const {
		return bonus > other.bonus;
	}
};

bool Cmp(int *a, int *b) {
	for (int q = 0; q<3; q++)
		if (a[q] != b[q])
			return a[q] < b[q];
	return false;
}

int n, k;
Item items[128];
Res resids[1024];

int roparams[128][3];
vector<string> rohas[128];

int params[3];
vector<string> has[3];

int ansparams[3];
int best[3];
vector<string> bestres[3];

char buff[1<<20];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		Item &it = items[i];
		scanf("%s", buff);
		it.name = buff;
		scanf("%s", buff);
		it.type = GetIndex(buff, ItemNames);
		for (int u = 0; u<3; u++)
			scanf("%d", &it.params[u]);
		scanf("%d", &it.size);
	}
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		Res &rs = resids[i];
		scanf("%s", buff);
		rs.name = buff;
		scanf("%s", buff);
		rs.type = GetIndex(buff, ResNames);
		scanf("%d", &rs.bonus);
		scanf("%s", buff);
		rs.home = -1;
		for (int j = 0; j<n; j++) if (buff == items[j].name)
			rs.home = j;
	}


	int sumplace = 0;
	for (int i = 0; i<n; i++) sumplace += items[i].size;
	bool ro = (sumplace == k);

	vector<Res> srt[3];
	if (ro) {
		for (int v = 0; v<n; v++)
			memcpy(roparams[v], items[v].params, sizeof(roparams[0]));
		for (int v = 0; v<k; v++) {
			const Res &rs = resids[v];
			roparams[rs.home][rs.type] += rs.bonus;
			rohas[rs.home].push_back(rs.name);
		}
	}
	else {
		for (int i = 0; i<k; i++)
			srt[resids[i].type].push_back(resids[i]);
		for (int i = 0; i<3; i++)
			sort(srt[i].begin(), srt[i].end());
	}


	memset(ansparams, -63, sizeof(ansparams));
	for (int i = 0; i<n; i++) if (items[i].type == 0)
		for (int j = 0; j<n; j++) if (items[j].type == 1)
			for (int u = 0; u<n; u++) if (items[u].type == 2) {
				int a[3] = {i, j, u};


				if (ro) {
					for (int q = 0; q<3; q++) {
						params[q] = roparams[a[q]][q];
						has[q] = rohas[a[q]];
					}
				}
				else {
					for (int q = 0; q<3; q++) {
						params[q] = items[a[q]].params[q];
						has[q].clear();
						for (int j = 0; j<min(int(srt[q].size()), items[a[q]].size); j++) {
							params[q] += srt[q][j].bonus;
							has[q].push_back(srt[q][j].name);
						}
					}
				}

				if (Cmp(ansparams, params)) {
					for (int q = 0; q<3; q++) {
						ansparams[q] = params[q];
						best[q] = a[q];
						bestres[q] = has[q];
					}
				}
			}

	for (int i = 0; i<k; i++) {
		bool used = false;
		for (int q = 0; q<3; q++)
			for (int j = 0; j<bestres[q].size(); j++)
				if (bestres[q][j] == resids[i].name)
					used = true;
		for (int q = 0; q<3; q++)
			if (!used && bestres[q].size() < items[best[q]].size) {
				bestres[q].push_back(resids[i].name);
				used = true;
			}
	}

	for (int q = 0; q<3; q++) {
		printf("%s %d", items[best[q]].name.c_str(), bestres[q].size());
		for (int i = 0; i<bestres[q].size(); i++)
			printf(" %s", bestres[q][i].c_str());
		printf("\n");
	}

	return 0;
}