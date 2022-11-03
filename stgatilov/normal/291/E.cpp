//#pragma comment(linker, "/STACK:20000000")
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
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int VERTS = 100<<10;
const int SIZE = 300<<10;

int n;
int father[VERTS];
string str[VERTS];
vector<int> sons[VERTS];

int len;
string image;
int pref[SIZE];

typedef pair<int, int> pii;
vector<pii> ans;

void DFS(int v, int pj) {
	for (int q = 0; q<sons[v].size(); q++) {
		int s = sons[v][q];
		
		const string& ss = str[s];
		int i = 0, j = pj;
		while (i < ss.size()) {
			if (ss[i] == image[j]) {
				i++; j++;
				if (j == len) {
					ans.push_back(pii(s, i));
					j = pref[j];
				}
			}
			else if (j)
				j = pref[j];
		    else
		    	i++;
		}

		DFS(s, j);
	}
}


char buff[SIZE];
int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	scanf("%d", &n);
	for (int i = 1; i<n; i++) {
		scanf("%d %s", &father[i], buff);
		father[i]--;
		sons[father[i]].push_back(i);
		str[i] = buff;
	}
	scanf(" %s", buff);
	image = buff;
	len = image.size();

	pref[0] = 0;
	int i = 1, j = 0;
	while (i < len) {
		if (image[i] == image[j]) {
			i++; j++;
			pref[i] = j;
		}
		else if (j)
			j = pref[j];
		else {
			i++;
			pref[i] = j;
		}
	}
//	for (int i = 0; i<=len; i++) printf("%d ", pref[i]); printf("\n");

	DFS(0, 0);

	printf("%d\n", ans.size());
//	for (int i = 0; i<ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);

	return 0;
}