#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 10, M = 1e3 + 10;
int n, l0, k0;
char s[N];
string t[M];

void solve(int l, int r, int len, int now, int k) {
    if (len == 0){
        for (int i = k0 + 1; i <= n; i++){
            for (int j = 1; j <= l0; j++){
                t[i] += s[l++];
            }
        }
        return ;
    }
    //printf("%d %d %d %d %d\n", l, r, len, now, k);
    int R = r, L = l, p = 0;
    for (int i = l; i <= l + k - 1; i++){
        if (s[i] < s[l + k - 1]){
            t[now + i - l] += s[i]; L++;
            for (int o = 1; o < len; o++) t[now + i - l] += s[R--];
            p ++; //cout << t[1] << endl;
        } else {
            t[now + i - l] += s[i]; L++;
        }
    }
    solve(L, R, len - 1, now + p, k - p);
}

int main() {
    scanf("%d%d%d%s", &n, &l0, &k0, s+1);
    sort(s + 1, s + 1 + n * l0);
    solve(1, n * l0, l0, 1, k0);
    sort(t + 1, t + n + 1);
    for (int i = 1; i <= n; i++) cout << t[i] << endl;
    return 0;
}

/*
3 2 2
abcdef

3 3 3
abcdefghi

*/