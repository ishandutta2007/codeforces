#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
using namespace std;

#define FOR(i,a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++ i)

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int, int> PII;

const double EPS = 1e-8;
const double PI = acos(-1.0);

const int maxlen = 100;

int memo[maxlen + 1][3][3][maxlen + 1];

int dfs(int len, int start, int end, int cnt)
{
    if (len == 1) {
        return start == end && cnt == 0;
    }
    int &ret = memo[len][start][end][cnt];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int dig = 0; dig < 3; ++ dig) {
        if (dig == 0 && end == 1) {
            if (dfs(len - 1, start, dig, cnt - 1)) {
                return ret = 1;
            }
        } else {
            if (dfs(len - 1, start, dig, cnt)) {
                return ret = 1;
            }
        }
    }
    return ret;
}

void print(int x)
{
    if (x == 0) {
        printf("A");
    } else if (x == 1) {
        printf("C");
    } else {
        printf("D");
    }
}

void print(int len, int start, int end, int cnt)
{
    if (len == 1) {
        print(start);
        return;
    }
    for (int dig = 0; dig < 3; ++ dig) {
        if (dig == 0 && end == 1) {
            if (dfs(len - 1, start, dig, cnt - 1)) {
                print(len - 1, start, dig, cnt - 1);
                print(end);
                return;
            }
        } else {
            if (dfs(len - 1, start, dig, cnt)) {
                print(len - 1, start, dig, cnt);
                print(end);
                return;
            }
        }
    }
    assert(false);
}

bool check(int k, int target, int s1, int e1, long long c1, int s2, int e2, long long c2)
{
    for (int i = 3; i <= k && c2 <= target; ++ i) {
        int s = s1, e = e2;
        long long c = c1 + c2 + (e1 == 0 && s2 == 1);
        s1 = s2; e1 = e2; c1 = c2;
        s2 = s; e2 = e; c2 = c;
    }
    return c2 == target;
}

int main()
{
    int k, target, n, m;
    scanf("%d%d%d%d", &k, &target, &n, &m);
    
    memset(memo, -1, sizeof(memo));
    
    for (int s1 = 0; s1 < 3; ++ s1) {
        for (int e1 = 0; e1 < 3; ++ e1) {
            for (int c1 = 0; c1 < n; ++ c1) {
                if (dfs(n, s1, e1, c1)) {
                    for (int s2 = 0; s2 < 3; ++ s2) {
                        for (int e2 = 0; e2 < 3; ++ e2) {
                            for (int c2 = 0; c2 < m; ++ c2) {
                                if (dfs(m, s2, e2, c2)) {
                                    if (check(k, target, s1, e1, c1, s2, e2, c2)) {
                                        print(n, s1, e1, c1);
                                        puts("");
                                        print(m, s2, e2, c2);
                                        puts("");
                                        exit(0);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    puts("Happy new year!");
    
    return 0;
}