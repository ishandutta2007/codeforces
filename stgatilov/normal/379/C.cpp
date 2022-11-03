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

typedef pair<int, int> pii;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    vector<pii> arr;
    int n;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        pii p;
        scanf("%d", &p.first);
        p.second = i;
        arr.push_back(p);
    }

    sort(arr.begin(), arr.end());

    vector<int> ans(n, -1);
    int last = 0;
    for (int i = 0; i<n; i++) {
        int curr = max(last+1, arr[i].first);
        ans[arr[i].second] = curr;
        last = curr;
    }

    for (int i = 0; i<n; i++) printf("%d ", ans[i]);

	return 0;
}