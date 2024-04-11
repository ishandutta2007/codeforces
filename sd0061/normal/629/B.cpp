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
const int N = 1000;

int n , a[N] , b[N];

int main() {
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int l , r; char s[3];
        scanf("%s%d%d" , s , &l , &r);
        for (int j = l ; j <= r ; ++ j) {
            if (*s == 'F')
                ++ a[j];
            else
                ++ b[j];
        }
    }

    int res = 0;
    for (int i = 0 ; i < N ; ++ i)
        res = max(res , min(a[i] , b[i]));
    cout << res + res << endl;
    return 0;
}