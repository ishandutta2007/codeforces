#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 200010
int cnt[10];
LL p[12];
LL n;
int m;
LL f[100][N];
void work() {
    cin >> n >> m;
    while (n) {
        ++ cnt[n % 10];
        n /= 10;
    }
    int i , j , k , l;
    p[0] = 1;
    for (i = 0 ; i < 10 ; ++ i) {
        if (i && cnt[i])
            f[i % m][p[i]] = 1;
        p[i + 1] = p[i] * (cnt[i] + 1);
    }
    for (j = 0 ; j < p[10] ; ++ j) {
        for (i = 0 ; i < m ; ++ i) {
            if (!f[i][j]) continue;
            for (l = 0 ; l < 10 ; ++ l) {
                int x = j / p[l] % (cnt[l] + 1);
                if (x < cnt[l]) {
                    f[(i * 10 + l) % m][j + p[l]] += f[i][j];
                }
            }
        }
    }
    cout << f[0][p[10] - 1] << endl;
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}