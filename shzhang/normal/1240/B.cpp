#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int seq[300005];
vector<int> idx[300005];

int lft[300005], rt[300005];
int f[300005];

int appears[300005];

int main()
{
    int q;
    scanf("%d", &q);
    for (int data = 1; data <= q; data++) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) appears[i] = 0;
        for (int i = 1; i <= n; i++) idx[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", seq + i);
        int distinct = 0;
        for (int i = 1; i <= n; i++) appears[seq[i]] = 1;
        for (int i = 1; i <= n; i++) distinct += appears[i];
        for (int i = 1; i <= n; i++) idx[seq[i]].push_back(i);
        //fprintf(stderr, "HERE");
        for (int i = 1; i <= n; i++) sort(idx[i].begin(), idx[i].end());
        for (int i = 1; i <= n; i++) lft[i] = idx[i].size() ? idx[i][0] : 0;
        for (int i = 1; i <= n; i++) if (idx[i].size()) rt[i] = idx[i][idx[i].size() - 1];
        //fprintf(stderr, "HERE");
        vector<int> good;
        for (int i = 1; i <= n; i++) if (lft[i]) good.push_back(i);
        int maxf = 1;
        int l = 0, r = 0;
        while (r < good.size()) {
            r++;
            if (r >= good.size()) break;
            if (rt[good[r-1]] > lft[good[r]]) l = r;
            maxf = max(maxf, r-l+1);
        }
        printf("%d\n", distinct-maxf);
    }
    return 0;
}