#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
char s[N];

int cnt;
vector<int> v[N];

typedef pair<int, int> pii;
set<pii> s0, s1;

int main() {
    gets(s);
    n = strlen(s);
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            if (s0.empty()) {
                printf("-1\n");
                return 0;
            }
            else {
                pii p = *s0.begin();
                s0.erase(p);
                v[p.second].push_back(i);
                s1.insert(pii(i, p.second));
            }
        }
        else {
            if (s1.empty()) {
                int p = cnt ++;
                v[p].push_back(i);
                s0.insert(pii(i, p));
            }
            else {
                pii p = *s1.begin();
                s1.erase(p);
                v[p.second].push_back(i);
                s0.insert(pii(i, p.second));
            }
        }
    }
    if (!s1.empty()) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i ++) {
        printf("%d ", v[i].size());
        for (int j = 0; j < v[i].size(); j ++) {
            printf("%d ", v[i][j] + 1);
        }
        puts("");
    }
}