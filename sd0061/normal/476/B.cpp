#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;
char s[N] , t[N];
int n , m;
int res , cnt;
void dfs(int k , int x) {
    if (k == n) {
        ++ cnt;
        if (x == m)
            ++ res;
    } else {
        if (t[k] != '-')
            dfs(k + 1 , x + 1);
        if (t[k] != '+')
            dfs(k + 1 , x - 1);
    }
}

int main() {
    scanf("%s%s" , s , t);
    n = strlen(s);
    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] == '+') ++ m;
        if (s[i] == '-') -- m;
    }
    dfs(0 , 0);
    printf("%.10f\n" , 1.0 * res / cnt);
}