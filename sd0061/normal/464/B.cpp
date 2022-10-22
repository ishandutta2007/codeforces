#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

typedef long long LL;

const int N = 1005;
int a[8][3];
int b[8][3];
pair<LL , int> v[8];

inline LL dot(int A[3] , int B[3]) {
    LL res = 0;
    for (int i = 0 ; i < 3 ; ++ i)
        res += (LL) A[i] * B[i];
    return res;
}

bool dfs(int k) {
    if (k >= 8) {
        int i , j , k;
        for (i = 0 ; i < 8 ; ++ i) {
            v[i] = make_pair(0LL , i);
            for (j = 0 ; j < 3 ; ++ j) {
                b[i][j] = a[i][j] - a[0][j];
                v[i].first += (LL) b[i][j] * b[i][j];
            }
        }
        sort(v , v + 8);
        if (!v[1].first) return 0;
        if (v[1].first != v[3].first) return 0;
        if (v[4].first != v[6].first) return 0;
        if (v[1].first * 2 != v[4].first) return 0;
        if (v[1].first * 3 != v[7].first) return 0;
        if (dot(b[v[1].second] , b[v[2].second])) return 0;
        if (dot(b[v[1].second] , b[v[3].second])) return 0;
        if (dot(b[v[2].second] , b[v[3].second])) return 0;

        for (i = 0 ; i < 3 ; ++ i) {
            int x = 0;
            for (j = 1 ; j <= 3 ; ++ j)
                x += b[v[j].second][i];
            if (x != b[v[7].second][i])
                return 0;
        }

        int p[3] = {4 , 5 , 6};
        do {
            for (k = 0 ; k < 3 ; ++ k) {

                int x = 0 , y = 0 , z = 0;
                x += b[v[1].second][k];
                x += b[v[2].second][k];
                y += b[v[1].second][k];
                y += b[v[3].second][k];
                z += b[v[2].second][k];
                z += b[v[3].second][k];
                if (x != b[v[p[0]].second][k] || y != b[v[p[1]].second][k] || z != b[v[p[2]].second][k])
                    break;
            }
            if (k >= 3)
                return 1;
        } while (next_permutation(p , p + 3));

        return 0;
    }

    do {
        if (dfs(k + 1))
            return 1;
    } while (next_permutation(a[k] , a[k] + 3));

    return 0;
}

void work() {
    int i , j;
    for (i = 0 ; i < 8 ; ++ i) {
        for (j = 0 ; j < 3 ; ++ j)
            scanf("%d",&a[i][j]);
        sort(a[i] , a[i] + 3);
    }
    if (dfs(0)) {
        puts("YES");
        for (i = 0 ; i < 8 ; ++ i) {
            for (j = 0 ; j < 3 ; ++ j)
                printf("%d%c" , a[i][j] , " \n"[j == 2]);
        }
    } else {
        puts("NO");
    }
}

int main() {
    work();
    return 0;
}