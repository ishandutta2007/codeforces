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

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	

    int tests;
    scanf("%d", &tests);
    for (int tt = 0; tt < tests; tt++) {
        int len, k;
        scanf("%d%d", &len, &k);

        vector<int> pos;
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            x--;
            pos.push_back(x);
        }
        
        sort(pos.begin(), pos.end());

        vector<int> holes;
        holes.push_back(pos[0] + (len - 1 - pos[k-1]));
        for (int i = 1; i < k; i++)
            holes.push_back(pos[i] - pos[i-1] - 1);

        sort(holes.begin(), holes.end());
        reverse(holes.begin(), holes.end());

        int64 saved = 0;
        int64 nowt = 0;
        for (int i = 0; i < holes.size(); i++) {
            int64 rem = holes[i] - 2 * nowt;
            if (rem <= 0)
                break;
            if (rem <= 2) {
                nowt += 1;
                saved += 1;
            }
            else {
                nowt += 2;
                saved += rem - 1;
            }
        }

        int ans = len - saved;
        printf("%d\n", ans);
    }

	return 0;
}