#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 107

int cnt[maxn];
int c[maxn][maxn];
int n;
int lans, sum;

#ifndef DEBUG
void
#else
bool
#endif
process()
{
#ifdef DEBUG
    if (scanf("%d", &n) != 1) {
        return false;
    }
#else
    scanf("%d", &n);
#endif
    sum = lans = 0;
    vector< int > cand;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cnt[i]);
        for (int j = 0; j < cnt[i]; ++j) {
            scanf("%d", &c[i][j]);
            sum += c[i][j];
        }
        for (int j = 0; j < cnt[i] / 2; ++j) {
            lans += c[i][j];
        }
        if (cnt[i] % 2 == 1) {
            cand.push_back(c[i][cnt[i] / 2]);
        }
    }
    sort(cand.rbegin(), cand.rend());
    for (int i = 0; i < int(cand.size()); i += 2) {
        lans += cand[i];
    }
    printf("%d %d\n", lans, sum - lans);
#ifdef DEBUG
    return true;
#endif
}

int
main(int argc, char **argv)
{
#ifdef DEBUG
    while (process());
#else
    process();
#endif
    return 0;
}