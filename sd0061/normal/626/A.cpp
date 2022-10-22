#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 200005;
const int Q = 1e9 + 7;

int n;
char str[N];
int cnt[26];
int main() {

    scanf("%d%s" , &n , str);
    int res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = i ; j < n  ; ++ j) {
            memset(cnt , 0 , sizeof(cnt));
            for (int k = i ; k <= j ; ++ k)
                ++ cnt[str[k] - 'A'];
            if (cnt['L' - 'A'] == cnt['R' - 'A'] && cnt['U' - 'A'] == cnt['D' - 'A'])
                ++ res;
            
        }
    }
    cout << res << endl;
    return 0;
}