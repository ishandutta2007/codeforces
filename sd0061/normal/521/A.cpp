#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;
int n ;
char str[N];
int cnt[26];

void work() {
    scanf("%d",&n);
    scanf("%s" , str);
    for (int i = 0 ; i < n ; ++ i) {
        ++ cnt[str[i] - 'A'];
    }
    int x = *max_element(cnt , cnt + 26);
    LL res = 1 , y = 0;
    for (int i = 0 ; i < 26 ; ++ i)
        if (cnt[i] == x)
            ++ y;
    while (n --)
        res *= y , res %= Q;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}