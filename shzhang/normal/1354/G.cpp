#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;

#define FIRST 1
#define SECOND 2
#define EQUAL 3

int n, k;

bool stone[1005];

int query(vector<int>& a, vector<int>& b)
{
    printf("? %d %d\n", (int)min(a.size(), b.size()), (int)min(a.size(), b.size()));
    for (int i = 0; i < min(a.size(), b.size()); i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < min(a.size(), b.size()); i++) printf("%d ", b[i]);
    printf("\n");
    fflush(stdout);
    char ans[10]; scanf("%s", ans);
    if (ans[0] == 'F') return FIRST;
    if (ans[0] == 'S') return SECOND;
    if (ans[0] == 'E') return EQUAL;
    exit(0);
}

int binsearch(vector<int>& vec, vector<int>& stones)
{
    if (vec.size() == 1) return vec[0];
    vector<int> left, right;
    for (int i = 0; i < ((int)(vec.size()) / 2); i++) {
        left.push_back(vec[i]);
    }
    for (int i = ((int)(vec.size()) / 2); i < vec.size(); i++) {
        right.push_back(vec[i]);
    }
    if (query(left, stones) == SECOND) {
        return binsearch(left, stones);
    } else {
        return binsearch(right, stones);
    }
}

void work(void) {
    for (int i = 0; i < 1005; i++) stone[i] = false;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    scanf("%d%d", &n, &k);
    int curmax = rng() % n + 1;
    for (int i = 1; i <= 30; i++) {
        int nxtp = curmax;
        while (nxtp == curmax) nxtp = rng() % n + 1;
        vector<int> a, b; a.push_back(curmax); b.push_back(nxtp);
        if (query(a, b) == SECOND) {
            curmax = nxtp;
        }
    }
    stone[curmax] = true;
    vector<int> stones; stones.push_back(curmax);
    int cur = 1;
    while (true) {
        vector<int> newcmp;
        while (cur <= n && newcmp.size() < stones.size()) {
            if (!stone[cur]) newcmp.push_back(cur);
            cur++;
        }
        if (query(newcmp, stones) == EQUAL) {
            for (int i = 0; i < newcmp.size(); i++) {
                stones.push_back(newcmp[i]); stone[newcmp[i]] = true;
            }
            newcmp.clear();
        } else {
            printf("! %d\n", binsearch(newcmp, stones)); fflush(stdout); return;
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}