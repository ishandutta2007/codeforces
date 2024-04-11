#pragma comment(linker, "/STACK:1000000000")
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
const int size = 10 * 1000 + 100;
const int lsize = 200 * 1000 * 1000;

char ans[lsize + 1];
int n, k, q;
int a[size];

int main() {
//    freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);

 	scanf("%d%d", &n, &k);

 	for (int i = 0; i <= lsize; i++)
 		ans[i] = 100;
 	for (int i = 0; i < n; i++) {
 		scanf("%d", &a[i]);
 		for (int j = 0; j <= k; j++)
 			ans[a[i] * j] = min((int) ans[a[i] * j], j);
 	}

 	scanf("%d", &q);
 	for (int i = 0; i < q; i++) {
 		int qr;
 		scanf("%d", &qr);

 		int lans = ans[qr];
 		for (int j = 0; j < n; j++) {
 			for (int p = 1; p <= k; p++) {
 				if (a[j] * p <= qr) {
 					lans = min(lans, p + ans[qr - a[j] * p]);
 				}
 			}
 		}

 		if (lans > k) {
 			printf("-1\n");
 		} else {
 			printf("%d\n", lans);
 		}
 	}

    return 0;
}