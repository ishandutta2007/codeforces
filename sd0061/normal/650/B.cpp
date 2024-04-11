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
const int N = 1000005;

int n , a , b , T;
char str[N];
int s[N];

LL W(int l , int r) {
    if (r > l) return 1 << 30;
    return (LL)(r + l + 1) + s[n + 1 + r] - s[n - l] + a * (l + r + r);
}

int cal() {    
    for (int i = n + 1 ; i <= n + n ; ++ i) {
        str[i] = str[i - n]; 
    }
    for (int i = 1 ; i <= n + n ; ++ i) {
        s[i] = s[i - 1] + (str[i] == 'w' ? b : 0);
    }
    int res = 0;
    for (int l = n - 1 , r = 0 ; l >= 0 ; -- l) {
        while (r <= l && l + r <= n - 1 && W(l , r) <= T)
            ++ r;
        if (r && W(l , r - 1) <= T) {
            res = max(res , l + r);            
        }
    }
    return res;
}

int main() {
    scanf("%d%d%d%d" , &n , &a , &b , &T);
    scanf("%s" , str + 1);
    int res = 0;
    res = max(res , cal());
    reverse(str + 2 , str + 1 + n);
    res = max(res , cal());
    cout << res << endl;
    return 0;
}