#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAXN = 1005;

char buf[MAXN][MAXN];
int n;
int sm[26][26];
int len[MAXN];
int used[MAXN];
vector< int > vals;

void
dfs(int x)
{
    used[x] = 1;
    for (int j = 0; j < 26; ++j) {
        if (!used[j] && sm[x][j]) {
            dfs(j);
        }
    }
    vals.push_back(x);
}

int
main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", buf[i]);
        len[i] = strlen(buf[i]);
    }
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        for (int j = i + 1; j < n && ok; ++j) {
            int min_len = min(len[i], len[j]);
            int ind = 0;
            while (ind < min_len && buf[i][ind] == buf[j][ind]) ++ind;
            if (ind == min_len) {
                if (isalpha(buf[i][ind])) {
                    ok = false;
                }
            } else {
                sm[buf[i][ind] - 'a'][buf[j][ind] - 'a'] = 1;
            }
        }
    }
    if (ok) {
        vals.clear();
        for (int i = 0; i < 26; ++i) {
            if (!used[i]) {
                dfs(i);
            }
        }
        reverse(vals.begin(), vals.end());
    }
    if (ok) {
        for (int i = 0; ok && i < 26; ++i) {
            for (int j = i + 1; ok && j < 26; ++j) {
                if (sm[vals[j]][vals[i]]) {
                    ok = false;
                }
            }
        }
    }
    if (ok) {
        for (auto x : vals) {
            putchar('a' + x);
        }
        puts("");
    } else {
        puts("Impossible");
    }
    return 0;
}