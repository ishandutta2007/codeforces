#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

#define ll long long

int n, m;
int l[100005];
int pos[100005];
int npos[100005];
int smin[100005];

int main()
{
    scanf("%d%d", &n, &m);
    int total = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", l + i);
        total += l[i];
        if (n - l[i] < i - 1) {
            printf("-1"); return 0;
        }
    }
    smin[m+1] = 1000000000;
    for (int i = m; i >= 1; i--) {
        smin[i] = min(smin[i+1], n - l[i] + 1 - i);
    }
    for (int i = 1; i <= m; i++) {
        pos[i] = i;
    }
    int needed = n - l[m] + 1 - pos[m];
    int shift = 0;
    npos[1] = 1;
    for (int i = 2; i <= m; i++) {
        int newpos = pos[i-1] + l[i-1];
        int mov = min(needed, min(newpos - pos[i], smin[i] - shift));
        shift += mov; needed -= mov; npos[i] = pos[i] + shift;
        //printf("%d %d %d ", newpos, smin[i], npos[i]);
    }
    //printf("%d", npos[m]);
    if (npos[m] != n - l[m] + 1) {
        printf("-1"); return 0;
    }
    for (int i = 1; i <= m; i++) printf("%d ", npos[i]);
    return 0;
}