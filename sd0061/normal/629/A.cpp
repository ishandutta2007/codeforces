#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 105;

int n;
char s[N][N];
int c[N] , r[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        scanf("%s" , s[i]);
        for (int j = 0 ; j < n ; ++ j)
            if (s[i][j] == 'C') {
                ++ c[i];
                ++ r[j];
            }
    }
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        res += c[i] * (c[i] - 1) / 2;
        res += r[i] * (r[i] - 1) / 2;        
    }
    cout << res << endl;
    return 0;
}