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
typedef unsigned int dword;

const int SIZE = 160;
const int SZ = (SIZE + 31) / 32;

void Set(dword *arr, int i) {
	arr[i >> 5] |= 1 << (i & 31);
}
dword Get(dword *arr, int i) {
	return (arr[i >> 5] >> (i & 31)) & 1;
}

int n, m;
char pict[SIZE][SIZE];

struct Field {
	dword a[SIZE][SZ];
};

int k;
char comms[1<<20];

int cc;
Field cf[2];

int exitx, exity;
Field pass;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif  
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i<n; i++)
		scanf("%s", pict[i]);

	int freecells = 0;
	memset(&pass, 0, sizeof(pass));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) {
			if (pict[i][j] != '#') {
				Set(pass.a[i + 3], j + 3);
				freecells++;
			}
			if (pict[i][j] == 'E') {
				exitx = i + 3;
				exity = j + 3;
			}
		}
	if (freecells == 1) {
		printf("0\n");
		return 0;
	}

	cc = 0;
	memcpy(&cf[cc], &pass, sizeof(pass));
	
	scanf("%s", comms);
	for (int q = 0; q<=k; q++) {

/*        for (int i = 0; i<SIZE; i++) {
        	for (int j = 0; j<SIZE; j++) {
        		char c = Get(pass.a[i], j) ? '.' : '#';
        		c += Get(cf[cc].a[i], j) ? '*' - '.' : 0;
        		printf("%c", c);
        	}
        	printf("\n");
        }*/
        if (q == k) break;

		char c = comms[q];
		bool final = true;
		for (int i = 0; i<SIZE; i++) {
			const Field &curr = cf[cc];
			Field &next = cf[cc^1];

			for (int j = 0; j<SZ; j++) {
				dword pos = curr.a[i][j];
				dword mask = pass.a[i][j];
				dword movpos = 0;
				dword revmask = 0;

				switch (c) {
					case 'R':
						movpos = (pos << 1);
						revmask = (mask >> 1);
						if (j > 0) movpos ^= curr.a[i][j-1] >> 31;
						if (j < SZ-1) revmask ^= (pass.a[i][j+1] & dword(1)) << 31;
						break;
					case 'L':
						movpos = (pos >> 1);
						revmask = (mask << 1);
						if (j < SZ-1) movpos ^= (curr.a[i][j+1] & dword(1)) << 31;
						if (j > 0) revmask ^= pass.a[i][j-1] >> 31;
						break;
					case 'D':
						if (i > 0) movpos = curr.a[i-1][j];
						if (i < SIZE-1) revmask = pass.a[i+1][j];
						break;
					case 'U':
						if (i < SIZE-1) movpos = curr.a[i+1][j];
						if (i > 0) revmask = pass.a[i-1][j];
						break;
				}

				dword res = (movpos & mask) | (pos & (~revmask));
				next.a[i][j] = res;

				if (final && res) {
					if (!(i == exitx && j == (exity >> 5) && res == (dword(1) << (exity & 31))))
						final = false;
				}
			}
        }
        cc ^= 1;

        if (final) {
			printf("%d\n", q+1);
			return 0;
        }
	}

	printf("-1\n");
	return 0;
}