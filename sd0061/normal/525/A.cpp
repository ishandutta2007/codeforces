#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , cnt[N] , res;
char str[N];

void work() {
    scanf("%d",&n);
    scanf("%s" , str);
    for (int i = 0 ; i + 1 < n ; ++ i) {
        ++ cnt[str[i << 1] - 'a'];
        if (!cnt[str[i << 1 | 1] - 'A']) {
            ++ res;            
        } else {
            -- cnt[str[i << 1 | 1] - 'A'];
        }
    }
    cout << res << endl;
}

int main() {
    work();
    return 0;
}