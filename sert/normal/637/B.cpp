#include <iostream>
#include <cstdio>
#include <cstring>
#include <unordered_set>
using namespace std;
typedef long long ll;

const int N = 2e5 + 34;
char s[N][12];
ll hsh[N], res;
int n, len;
unordered_set <ll> us;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        gets(s[i]);
        len = strlen(s[i]);
        res = 0;
        for (int j = 0; j < len; j++)
            res = res * 30 + s[i][j] - 'a' + 1;
        hsh[i] = res;
    }
    for (int i = n - 1; i >= 0; i--)
        if (us.find(hsh[i]) == us.end()) {
            us.insert(hsh[i]);
            printf("%s\n", s[i]);
        }
    return 0;
}