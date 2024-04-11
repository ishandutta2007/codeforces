#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

const int N = 111;

int a[N][N], len[N];
int hash[N];
int n;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &len[i]);
        for(int j = 1; j <= len[i]; j++)
            scanf("%d", &a[i][j]);
    }
    
    for(int i = 1; i <= n; i++) {
        bool flag = true;
        for(int j = 1; j <= 100; j++)
            hash[j] = 0;
        for(int j = 1; j <= len[i]; j++)
            hash[a[i][j]] = 1;
        for(int j = 1; j <= n; j++)
            if (i != j) {
                bool has = false;
                for(int k = 1; k <= len[j]; k++) {
                    if (hash[a[j][k]] == 0)
                        has = true;
                }
                if (!has)
                    flag = false;
            }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}