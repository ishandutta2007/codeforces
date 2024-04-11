#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 200005;
int n , m , s[N] , L[N];
char str[N];

void work() {
    scanf("%d%d%s" , &n , &m , str);
    LL res = (LL)n * (m - 1);
    int cnt = 0;
    for (int i = 0 ; i + 1 < n ; ++ i) {
        cnt += (str[i] != str[i + 1]);
        res += (LL)cnt * (m - 1);
    }
    cnt = 0;
    for (int i = n - 2 ; i >= 0 ; -- i) {
        cnt += (str[i] != str[i + 1]);
        res += (LL)cnt * (m - 1);
    }
    for (int i = 1 ; i < n ; ++ i) {
        if (i >= 2 && str[i] == str[i - 2])
            L[i] = L[i - 2];
        else
            L[i] = i;
        s[i] = s[i - 1] + (str[i] != str[i - 1]);
        int p = max(L[i] , L[i - 1]) - 1;        
        res -= s[i] - s[p];        
    }        
    cout << res << endl;
}

int main() {
    work();
    return 0;
}