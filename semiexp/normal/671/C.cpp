#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, A[202020];
vector<int> divs[202020];
vector<pair<int, int> > eves[202020];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);

	for (int i = 0; i < N; ++i) {
		for (int j = 1; j * j <= A[i]; ++j) {
			if (A[i] % j == 0) {
				divs[j].push_back(i);
				if (A[i] / j != j) divs[A[i] / j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= 200000; ++i) if (divs[i].size() >= 2) {
		int la = divs[i][0], ra = divs[i][divs[i].size() - 2];
		int lb = divs[i][1], rb = divs[i][divs[i].size() - 1];

		eves[0].push_back({ ra, i });
		eves[la + 1].push_back({ rb, i });
		eves[lb + 1].push_back({ N, i });
	}

	set<pair<int, int> > S;
	S.insert({ N, 0 });
	const int big = 3000000;
	S.insert({ 0, big + 1});
	i64 ret = 0, tot = 0;
	for (int i = 0; i < N; ++i) {
		if (i > 0) eves[i].push_back({ i, big });
		for (auto e : eves[i]) {
		//	printf("%d: %d %d\n", i, e.first, e.second);
			int preval = S.lower_bound({ e.first, -1 })->second;
			int prepos = e.first;
			if (preval >= e.second) continue;

			S.insert({ e.first, e.second });
			for (;;) {
				auto ptr = S.lower_bound({ e.first, e.second });
				--ptr;

				ret += (i64)(e.second - preval) * (prepos - ptr->first);
				preval = ptr->second;
				prepos = ptr->first;
				if (ptr->second <= e.second) {
					S.erase(ptr);
				} else {
					break;
				}
			}
		}
		tot += ret - (i64)big * i;
	}

	cout << tot << endl;

	return 0;
}