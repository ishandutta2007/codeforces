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
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n , k;
char str[N];
int s[N];

bool check(int v) {
    for (int i = 1 ; i <= n ; ++ i) {
        if (str[i - 1] == '0') {
            int l = max(0 , i - v);
            int r = min(n , i + v);
            if (s[r] - s[l - 1] >= k + 1)
                return 1;
        }
    }
    return 0;
}

int main() {

    scanf("%d%d%s" , &n , &k , str);
    for (int i = 0 ; i < n ; ++ i)
        s[i + 1] = s[i] + (str[i] == '0');
    int l = 0 , r = n;
    while (l < r) {
        int m = l + r >> 1;
        if (check(m))
            r = m;
        else
            l = m + 1;
    }
    cout << r << endl;
    return 0;
}