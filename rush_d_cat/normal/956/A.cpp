#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 20000 + 10;
int n, m, cnt[N];
char s[102];

vector<int> v[102];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) {
        scanf("%s", s+1);
        for (int j = 1 ;j <= m; j ++) {
            if (s[j] == '#') v[i].push_back(j);
        }
    }
    sort(v+1, v+1+n);
    bool ok = 1;
    for (int i = 1; i <= n; i ++) {
        if ((i == 1) || (i >= 2 && v[i] != v[i-1]) ) {
            for (int j = 0; j < v[i].size(); j ++) {
                cnt[v[i][j]] ++;
                if (cnt[v[i][j]] == 2)
                    ok = 0;
            }
        }
    }
    printf("%s\n", ok ? "Yes" : "No");
}