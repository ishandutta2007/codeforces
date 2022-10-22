#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const LL Q = 1e9 + 9;
int n;
char s[N] , t[N];

void work() {
    scanf("%d" , &n);
    scanf("%s%s" , s , t);
    int i , x = 0;
    int L = 0 , R = n - 1;
    while (s[L] == t[L])
        ++ L;
    while (s[R] == t[R])
        -- R;
    int res = 0;
    for (i = L ; i < R ; ++ i)
        if (s[i] != t[i + 1])
            break;
    if (i >= R) ++ res;
    swap(s , t);
    for (i = L ; i < R ; ++ i)
        if (s[i] != t[i + 1])
            break;
    if (i >= R) ++ res;
    cout << res << endl;
}

int main() {
    work();
    return 0;
}