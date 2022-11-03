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

const int SIZE = 7<<10;
const int WIDTH = 120<<10;
const int LOGW = 20;

int n, w;
int width[SIZE];
int father[LOGW+1][WIDTH];

int LiftUp(int pos, int num) {
    int lvl = 0;
    while (num > 0) {
        while ((1<<(lvl+1)) <= num) lvl++;
        while ((1<<lvl) > num) lvl--;
        pos = father[lvl][pos];
        num -= 1<<lvl;
    }
    return pos;
}

struct Segment {
    int level;
    int left, right;    //incl
    int elem;
    bool operator< (const Segment &s) const {
        return elem < s.elem;
    }
};

int m;
map<int, vector<Segment>> segs;

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
    scanf("%d", &n);
    n--;
    n = max(n, 3);

    width[0] = 1;
    for (int i = 0; i<n; i++) {
        width[i+1] = width[i];
        for (int j = 0; (1<<j)-1 < width[i]; j++)
            width[i+1]++;
    }

/*    int v = 0;
    for (int i = 0; i<n; i++) {
        printf("%d %d\n", i, width[i]);
        v += width[i];
    }
    printf("%d\n", v);*/

    int qq = 0;
    for (int i = 0; i < width[n-1]; i++) {
        bool two = ((i+1) & i) == 0;
        int c = 1 + int(two);
        for (int j = 0; j<c; j++)
            father[0][qq++] = i;
    }
    w = width[n];
    for (int l = 0; l<LOGW; l++)
        for (int i = 0; i<w; i++)
            father[l+1][i] = father[l][father[l][i]];

    
    scanf("%d", &m);
    for (int i = 0; i<m; i++) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            Segment ns;
            scanf("%d%d%d%d", &ns.level, &ns.left, &ns.right, &ns.elem);
            ns.level--;
            ns.left--;
            ns.right--;
            segs[ns.elem].push_back(ns);
        }
        else {
            int lvl, pos;
            scanf("%d%d", &lvl, &pos);
            lvl--;  pos--;

            int ans = 0;
            for (auto it = segs.begin(); it != segs.end(); it++) {
                const auto& vct = it->second;

                bool ok = false;
                for (int t = 0; !ok && t<vct.size(); t++) {
                    Segment s = vct[t];

                    if (s.level < lvl) continue;
                    int diff = s.level - lvl;
                    int nl = LiftUp(s.left, diff);
                    int nr = LiftUp(s.right, diff);

                    if (pos >= nl && pos <= nr)
                        ok = true;
                }

                ans += int(ok);
            }

            printf("%d\n", ans);
        }
    }
        

	return 0;
}