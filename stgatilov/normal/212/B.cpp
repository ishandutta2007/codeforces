//#pragma comment(linker, "/STACK:30000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
typedef long long int64;
#define E(c) fprintf(stderr, #c)
#define Eo(c) std::cerr << #c << " = " << (c) << std::endl

const int SIZE = 1<<20;
const int CNT = 10<<10;
const int CHARS = 26;

int n, m;
char str[SIZE];
int nxt[SIZE][CHARS];

int arr[CNT];
int k;
map<int, int> setmap;
int ans[CNT];

typedef pair<int, int> pii;
const int HASH = 1<<20;
pii hsh[HASH];
inline int HashF(int x) { return (x * 7) & (HASH-1); }

char buff[32];
int main() {
#ifdef _CRT_SECURE_NO_DEPRECATE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    scanf("%s", str);
    n = strlen(str);

    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
    	scanf("%s", buff);
    	int t = 0;
    	for (int j = 0; buff[j]; j++)
    		t |= 1<<(buff[j] - 'a');
		arr[i] = t;
    }

    for (int j = 0; j<CHARS; j++)
	    nxt[n][j] = n;
	for (int i = n-1; i>=0; i--) {
	    for (int j = 0; j<CHARS; j++)
	    	if (str[i] == 'a' + j)
			    nxt[i][j] = i;
			else
				nxt[i][j] = nxt[i+1][j];
	}

	for (int i = 0; i<m; i++)
		setmap[arr[i]] = 0;
	k = 0;
	memset(hsh, -1, sizeof(hsh));
	for (map<int, int>::iterator it = setmap.begin(); it != setmap.end(); it++) {
		it->second = k++;
		int pos = HashF(it->first);
		while (hsh[pos].first >= 0) pos = (pos + 1) & (HASH-1);
		hsh[pos] = *it;
	}

	for (int left = 0; left<n; left++) {
		int s = 1 << (str[left]-'a');
		int right = left;
		while (right < n) {
//			printf("??? %d %d: %d\n", left, right, s);
			if (left==0 || !(s & (1 << (str[left-1]-'a')))) {
//				printf("%d %d: %d\n", left, right, s);
/*				if (setmap.find(s) != setmap.end())
					ans[setmap[s]]++;*/
				int pos = HashF(s);
				while (hsh[pos].first >= 0) {
					if (hsh[pos].first == s) {
						ans[hsh[pos].second]++;
						break;
					}
					pos = (pos + 1) & (HASH-1);
				}
			}

			int tmin = n;
			int best = -1;
			for (int c = 0; c<CHARS; c++) {
				if (s & (1<<c)) continue;
				if (tmin > nxt[right][c]) {
					tmin = nxt[right][c];
					best = c;
				}
			}

			right = tmin;
			s |= (1<<best);
		}
	}

	for (int i = 0; i<m; i++)
		printf("%d\n", ans[setmap[arr[i]]]);
	
	return 0;
}