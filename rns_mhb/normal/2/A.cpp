#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pii pair <int, int>
#define N 1010

int n, s, i, j, k, fi, ans, maxi = 0, last[N], len[N];
char name[40], nm[N][40];
map <string, int> num;
vector <pii> sum[N];

int main() {
    scanf("%d", &n);
    for (i = 0, j = 0; i < n; i ++) {
        scanf("%s %d", name, &s);
        if (!num[name]) num[name] = ++ j, strcpy(nm[j], name);
        sum[num[name]].push_back(mp(s, i));
    }
    for (i = 1; i <= j; i ++) {
        len[i] = sum[i].size() - 1;
        for (k = 0; k < len[i]; k ++) sum[i][k+1].first += sum[i][k].first;
    }
    for (i = 1; i <= j; i ++) maxi = max(maxi, sum[i][len[i]].first);
    for (i = 1; i <= j; i ++) {
        for (k = 0; k < len[i] && sum[i][k].first < maxi; k ++);
        last[i] = sum[i][k].second;
    }
    for (i = 1, fi = n; i <= j; i ++)
        if (sum[i][len[i]].first == maxi && fi > last[i]) fi = last[i], ans = i;
    puts(nm[ans]);

    return 0;
}